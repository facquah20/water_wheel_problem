#include <iostream>
#include <vector>



int main(int argc, char* argv[]) {
    
    const double prandtl_number = 10.0;
    const double reyleigh_number = 28.0;
    const double geometric_aspect_ratio = 2.666667;


    const double dt = 0.01; //time step
    const double simulation_time = 50.0; //total simulation time
    int total_steps = static_cast<int>(simulation_time / dt);

    /*
        x - speed and direction of the water wheel
        y - temperature difference between ascending and desceding current
        z- deviation of vertical temperature profile from linearity
     */
    std::vector<double> x(total_steps), y(total_steps), z(total_steps);

    x[0] = 1.0; // initial speed of the water wheel
    y[0] = 1.0; // initial temperature difference
    z[0] = 1.0; // initial deviation of vertical temperature profile

    /**
     * using a high order method explicit taylor series expansion to solve the system of ODEs
     * 
     */
    for(int i = 0; i < total_steps - 1; ++i) {
      double x_dot, y_dot, z_dot;
      x_dot = prandtl_number*(y[i]-x[i]);
      y_dot = x[i]*(reyleigh_number-z[i]) - y[i];
      z_dot = x[i]*y[i] - geometric_aspect_ratio*z[i];

      double x_dot_dot = -prandtl_number * (y_dot - x_dot);
      double y_dot_dot = x_dot * (reyleigh_number -z[i]) + x[i]*(-z[i]) - y_dot;
      double z_dot_dot = x_dot*y[i] - x[i]*y_dot + geometric_aspect_ratio*z_dot;

        x[i+1] = x[i] + dt * x_dot + 0.5 * dt * dt * x_dot_dot + 0.1666666667 * dt * dt * dt * x_dot_dot;
        y[i+1] = y[i] + dt * y_dot + 0.5 * dt * dt * y_dot_dot + 0.1666666667 * dt * dt * dt * y_dot_dot;
        z[i+1] = z[i] + dt * z_dot + 0.5 * dt * dt * z_dot_dot + 0.1666666667 * dt * dt * dt * z_dot_dot;

        std::cout << x[i] <<", "<< y[i] << ", " << z[i] << std::endl;
    }

     

    

    
    return 0;
}