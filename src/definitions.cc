#ifndef __DEFINITIONS__
#define __DEFINITIONS__
#define kScreenWith (800)
#define kScreenHeight (900)

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