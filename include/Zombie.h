#ifndef ZOMBIE_H
#define ZOMBIE_H

class Zombie
{
	public:
		Zombie(int pos):position_(pos) {}

		int getFullHP() { return full_hp_; }
		int getHP() { return hp_; }
		int getPos()const { return position_; }
        int getAttack()const { return power_; }
		void setPos(int i) { position_ = i; }
		bool isDied(){ return hp_ <= 0 ;}

		Zombie& operator += ( int life ){
            hp_ += life ;
            if( hp_ > full_hp_ ) hp_ = full_hp_ ;
            return *this ;
		}
        Zombie& operator -= ( int hurt ){
            hp_ -= hurt ;
            if( hp_ < 0 ) hp_ = 0 ;
            return *this ;
		}

	private:
		int position_;
		int hp_ = full_hp_;
		constexpr static int power_ = 15;
		constexpr static int full_hp_ = 40;
};

#endif // ZOMBIE_H
