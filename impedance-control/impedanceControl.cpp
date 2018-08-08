/*
	Author: Guilherme R. Moreira
	Local: University of São Paulo
	Creation: 2018, August
*/

#include "impedanceControl.hpp"

ImpedanceControl::ImpedanceControl(double m, double b, double k, float ts = 0.012)
{
	this->m = m;
	this->b = b;
	this->k = k;
	this->ts = ts;	
}

Integration::Integration(double m, double b, double k, float ts = 0.012)
{
	this->m = m;
	this->b = b;
	this->k = k;
	this->ts = ts;	
}

double Integration::correction(double reference_force)
{
	this->ddx = (reference_force-this->k*this->x-this->b*this->dx)/this->m
    this->dx = (this->ts/(2*(this->ddx+this->ddx_ant)))+this->dx_ant
    this->x = (this->ts/(2*(this->dx+this->dx_ant)))+this->x_ant

    this->x_ant = this->x
    this->dx_ant = this->dx
    this->ddx_ant = this->ddx

    return this->x
}

Discretization::Discretization(double m, double b, double k, float ts = 0.012)
{
	this->m = m;
	this->b = b;
	this->k = k;
	this->ts = ts;	
}

double Discretization::correction(double reference_force)
{
	double ts2 = (double) this->ts * this->ts
    double den = (4*this->m)+(2*this->ts*this->b)+(ts2*this->k)
    double b1 = 2*ts2*this->k-8*this->m
    double b2 = 4*this->m-2*this->ts*this->b+ts2*this->k

    this->x = (ts2*reference_force+2*ts2*this->force_ant+ts2*this->force_ant2-b1*this->x_ant-b2*this->x_ant2)/den

    this->x_ant2 = this->x_ant
    this->x_ant = this->x
    this->force_ant2 = this->force_ant
    this->force_ant = reference_force

    return this->x
}
