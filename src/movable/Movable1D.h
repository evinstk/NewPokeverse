#ifndef MOVABLE_H
#define MOVABLE_H

/**
 * Class: Movable1D
 * ================
 * Contains state information on direction in
 * a 1-D context. Knowss nothing of the context
 * Contains state information on direction in
 * like position and depends on nothing. States
 * are like velocity. Use this in composition
 * to encapsulate directed movement information.
 */
class Movable1D {
 public:
  class MoveState {
   public:
    enum Type {
      NEGATIVE = -1,
      STATIONARY = 0,
      POSITIVE = 1
    };
    virtual Type getType() const = 0;
    virtual void posPress() = 0;
    virtual void negPress() = 0;
    virtual void posRelease() = 0;
    virtual void negRelease() = 0;
  };

  Movable1D();
  ~Movable1D();

  MoveState *getStationary() const;
  MoveState *getMovingPos() const;
  MoveState *getMovingNeg() const;

  void setState(MoveState *move_state);
  MoveState::Type getStateType() const;
  void posPress();
  void negPress();
  void posRelease();
  void negRelease();
 private:
  MoveState *_stationary;
  MoveState *_moving_neg;
  MoveState *_moving_pos;

  MoveState *_state;
};

#endif /* MOVABLE_H */
