# Problem Set: The Chaotic Waterwheel (Lorenz Attractor Simulation)

## Background & Physics
Derived by meteorologist Edward Lorenz in 1963, this system models atmospheric convection—specifically how fluid circulates when heated from below and cooled from above. It behaves identically to a physical waterwheel with leaky buckets placed around its rim fed by a steady stream from the top. 

Depending on the fluid properties, the system displays chaotic transitions: it can stay static, rotate smoothly in one direction, or spontaneously reverse its rotation direction unpredictably forever. This system is famous for demonstrating the **"Butterfly Effect"**—extreme sensitivity to initial conditions.

---

## The System Equations
The system state is defined by a 3D vector $\mathbf{x} = [x, y, z]^T$, where:
*   $x$: The speed and direction of the wheel's rotation (angular velocity).
*   $y$: The temperature difference between the ascending and descending currents.
*   $z$: The deviation of the vertical temperature profile from linearity.

The dynamics are governed by three coupled, non-linear first-order differential equations:

$$\frac{dx}{dt} = \sigma (y - x)$$

$$\frac{dy}{dt} = x (\rho - z) - y$$

$$\frac{dz}{dt} = x y - \beta z$$

### System Parameters
To trigger the classical chaotic regime, use the following standard meteorological constants:
*   $\sigma = 10.0$ (Prandtl number)
*   $\beta = 8/3 \approx 2.666667$ (Geometric aspect ratio)
*   $\rho = 28.0$ (Rayleigh number / heating threshold)

---

## Initial Value Problem (IVP)
To begin your numerical simulation, initialize the state variables just slightly off-center:

*   $x(0) = 1.0$
*   $y(0) = 1.0$
*   $z(0) = 1.0$

### Simulation Objective
*   **Time Span:** $t = 0$ to $t = 50$ seconds.
*   **Suggested Time Step:** $\Delta t \le 0.01$ seconds (or lower if using a lower-order integration method to minimize numerical drift).

---

## Computational Implementation Goals
1.  Implement a numerical solver loop (such as **RK4** or a high-order explicit **Taylor Series Method**).
2.  Log the output coordinates $(x, y, z)$ at each time step to a structured file format (e.g., `.csv` or `.dat`).
3.  *(Optional)* Plot the results in a 3D phase space ($x$ vs $y$ vs $z$) to visualize the twin-lobed geometric structure known as the **Lorenz Butterfly Attractor**.


## How to Run the simulation
1. Locate `scripts.sh` in your directory and run bash `bash scripts.sh` .
2. simulation_results.png file will be saved in your directory. Take a look at the plot.

