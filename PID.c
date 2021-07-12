#include "PID.h"

void shift_registers(PID *pid) {
    pid->err[2] = pid->err[1];
    pid->err[1] = pid->err[0];
    pid->err[0] = pid->desired_value - *(pid->parameter);
    pid->output[1] = pid->output[0];
}


void compute_PID(PID *pid) {
    shift_registers(pid);
    pid->output[0] = pid->output[1] + pid->Kp * ((1 + pid->dt / pid->Ti + pid->Td / pid->dt) + (-1.0 + 2 * pid->Td / pid->dt) + (pid->Td / pid->dt * pid->err[2]))

}

void set_PID_params(PID *pid, float *parameter, float Kp, float Ki, float Kd, float dt) {
    pid->Ti = Kp / Ki;
    pid->Td = Kd / Kp;
    pid ->Kp = Kp;
    pid ->dt = dt;
    pid->parameter = parameter;
}