#ifndef MOVABLE_H
#define MOVABLE_H

class Movable1D: public IMovable1D {
 public:
  class MoveState {
   public:
    virtual char getDirection() const = 0;
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
  char getDirection() const;
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
