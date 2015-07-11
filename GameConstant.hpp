#ifndef GAMECONSTANTCLASS
#define GAMECONSTANTCLASS

class GameConstant {
	public:
		GameConstant(
		double alfa, 			double dtime, 
		double threshold, 	int shots, int max_x, int max_y,  
		int w, int l,
		int ball_radius, int p_radius, int p_offset) {
			alpha = alfa;
			dt = dtime;
			vel_threshold = threshold;
			num_shots = shots;
			max_x_vel = max_x;
			max_y_vel = max_y;
			width = w;
			length = l;
			b_radius = ball_radius;
			pocket_radius = p_radius;
			pocket_offset = p_offset;
		}
		GameConstant ()
		{
			//HI
		}
	private:
		double alpha;
		double dt;
		
		double vel_threshold;
		int num_shots;	
		int max_x_vel;
		int max_y_vel;
		
		int width;
		int length;
		
		int b_radius;
		int pocket_radius;
		int pocket_offset;
	
	public:
		double Alpha() { return alpha; }
		double Dt() { return dt; }
		double VelocityThreshold() { return vel_threshold; }
		int NumShots() { return num_shots; }
		int MaxYVelocity() { return max_y_vel; }
		int MaxXVelocity() { return max_x_vel; }
		
		int Width() { return width; }
		int Length() { return length; }
		
		int BallRadius() { return b_radius;	}
		int PocketRadius() { return pocket_radius; }
		int PocketOffset() { return pocket_offset; }
};

#endif
