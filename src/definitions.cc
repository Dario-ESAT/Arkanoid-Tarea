#ifndef __DEFINITIONS__
#define __DEFINITIONS__
#define kScreenWidth (800)
#define kScreenHeight (900)
struct hitbox {
  float x1,y1,x2,y2;
};

class EntityClass{
  protected:
  int id;
  bool alive;

  public:
  int getId() {
  	return this->id;
  }

  void setId(int id) {
  	this->id = id;
  }

  bool getAlive() {
  	return this->alive;
  }

  void setAlive(bool alive) {
  	this->alive = alive;
  }
};

#endif