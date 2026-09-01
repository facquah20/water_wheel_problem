#!/bin/bash
# This script is used to run the water wheel problem simulation.

g++ -pg -O3 -o water_wheel_simulation simulation_code.cpp 

time ./water_wheel_simulation > output.csv

if [ $? -eq 0 ]; then
    echo "Simulation completed successfully. Output saved to output.csv"
else
    echo "Simulation failed. Please check the code for errors."
fi

if [ -f output.csv ]; then
    echo "Output file exists. You can analyze the results."
else
    echo "Output file not found. Please check the simulation code."
    EXIT 1
fi


python3 graph.py