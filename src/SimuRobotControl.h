#ifndef VSSS_SIMU_ROBOT_H
#define VSSS_SIMU_ROBOT_H

#include <ostream>
#include <utility>
#include <include.h>
#include <mujoco.h>

class SimuRobotControl {
public:
	Point position{};
	float orientation{};

	Target target{};
	Command command = Command::None;

	Wheel left{};
	Wheel right{};

	void set_target(Command command, Target target);
	WheelVelocity control_step(Point position, float orientation,
	                           WheelVelocity wheel_vel, float time);
	TargetVelocity run_control();

	TargetVelocity position_control();
	TargetVelocity uvf_control();
	TargetVelocity orientation_control();
	TargetVelocity vector_control(float target_theta,
	                              float velocity, bool enable_backwards);
	bool backwards_select(float theta_error);
};

#endif //VSSS_SIMU_ROBOT_H
