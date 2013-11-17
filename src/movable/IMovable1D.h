#ifndef IMOVABLE_1D_H
#define IMOVABLE_1D_H

/**
 * Inteface: Movable1D
 * ===================
 * Contains state information on direction in
 * a 1-D context. Knows nothing of the context
 * Contains state information on direction in
 * like position and depends on nothing. States
 * are like velocity. Use this in composition
 * to encapsulate directed movement information.
 */
class IMovable1D {
 public:
  virtual char getDirection() const = 0;
  virtual void posPress() = 0;
  virtual void negPress() = 0;
  virtual void posRelease() = 0;
  virtual void negRelease() = 0;
};

#endif /* IMOVABLE_1D_H */
