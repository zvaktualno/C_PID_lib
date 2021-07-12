#ifndef PID_H
#define PID_H

typedef struct {
    float output[2];
    float dt;
    float Kp, Td, Ti;
    float *parameter;
    float err[3];
    float desired_value;
} PID;

void shift_registers(PID *pid);
void compute_PID(PID *pid);
void set_PID_params(PID *pid, float *param, float Kp, float Ki, float Kd, float dt);

#endif