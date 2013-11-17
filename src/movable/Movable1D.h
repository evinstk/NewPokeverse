#ifndef MOVABLE_H
#define MOVABLE_H

class Movable1D {
 public:
  class MoveState {
   public:
    virtual char getDirection() const = 0;
    virtual void posBump() = 0;
    virtual void negBump() = 0;
  };

  Movable1D();
  ~Movable1D();

  MoveState *getStationary() const;
  MoveState *getMovingPos() const;
  MoveState *getMovingNeg() const;

  void setState(MoveState *move_state);
  char getDirection() const;
  void posBump();
  void negBump();
 private:
  MoveState *_stationary;
  MoveState *_moving_neg;
  MoveState *_moving_pos;

  MoveState *_state;
};

#endif /* MOVABLE_H */
