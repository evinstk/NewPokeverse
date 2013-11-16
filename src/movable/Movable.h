#ifndef MOVABLE_H
#define MOVABLE_H

/**
 * Class: Movable
 * ==============
 * Contains state information on direction in
 * a 2-D context. Knows nothing of the context
 * like position and depends on nothing. States
 * are like velocity. Use this in composition
 * to encapsulate directed movement information.
 */
class Movable {
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

  Movable();
  ~Movable();

  MoveState *getXStationary() const;
  MoveState *getMovingLeft() const;
  MoveState *getMovingRight() const;

  void setXState(MoveState *move_state);
  MoveState::Type getXStateType() const;
  void rightPress();
  void leftPress();
  void rightRelease();
  void leftRelease();

  MoveState *getYStationary() const;
  MoveState *getMovingUp() const;
  MoveState *getMovingDown() const;

  void setYState(MoveState *move_state);
  MoveState::Type getYStateType() const;
  void upPress();
  void downPress();
  void upRelease();
  void downRelease();
 private:
  MoveState *_x_stationary;
  MoveState *_moving_left;
  MoveState *_moving_right;

  MoveState *_x_state;

  MoveState *_y_stationary;
  MoveState *_moving_up;
  MoveState *_moving_down;

  MoveState *_y_state;
};

#endif /* MOVABLE_H */
