/*
	Author: Guilherme R. Moreira
	Local: University of São Paulo
	Creation: 2018, August
*/

#ifndef IMPEDANCE_CONTROL_HPP
#define IMPEDANCE_CONTROL_HPP

class ImpedanceControl
{
public:
	ImpedanceControl(double m, double b, double k, float ts = 0.012);
	//~ImpedanceControl();

private:
	double m;
	double b;
	double k;
	double ts;
};

class Integration()
{
public:
	Integration(double m, double b, double k, float ts = 0.012);
	double correction(double reference_force);

private:
	double x = 0;
	double dx = 0;
	double ddx = 0;
	double x_ant = 0;
	double dx_ant = 0;
	double ddx_ant = 0;
};

class Discretization()
{
public:
	Discretization(double m, double b, double k, float ts = 0.012);
	double correction(double reference_force);

private:
	double x = 0;
	double x_ant = 0;
	double x_ant2 = 0;
	double force_ant = 0;
	double force_ant2 = 0;
};


#endif //IMPEDANCE_CONTROL_HPP


