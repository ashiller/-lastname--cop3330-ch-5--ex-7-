/*
*  UCF COP3330 Fall 2021 Assignment 5 Solution
*  Copyright 2021 Anthony Shiller
*/

#include <iostream>
#include "std_lib_facilities.h"
using namespace std;

double a,b,c;

void solve()
{
	cout << "Please enter three floating-point numbers (a b c) to be used as the coefficients in a*x*x + b*x + c == 0: ";

	while (cin>>a>>b>>c) {
		if(a==0) {

			if (b==0)
				cout << "no root (since x isn't used)\n";
			else
				cout << "x == " << -c/b << '\n';
		}
		else if (b==0) {
			double ca = -c/a;
			if (ca == 0)
				cout << "x==0\n";
			else if (ca < 0)
				cout << "no real roots\n";
			else
				cout << "two real roots: " << sqrt(ca) << " and " << -sqrt(ca) << '\n';
		}
		else {
			double sq = b*b-4*a*c;
			if (sq==0)
				cout << "one real root: " << -b/(2*a) << '\n';
			else if (sq<0)
				cout << "no real roots\n";
			else
				cout << "two real roots: " << setprecision(12) << (-b+sqrt(sq))/(2*a) << " and " << (-b-sqrt(sq))/(2*a) << '\n';
		}
		cout << "please try again (enter a b c): ";
	}
}
const double epsilon = 1.0e-7;
double found(double x)
{
	double e = a*x*x+b*x+c;
	if (e==0) return x;
	if (0<e && epsilon<e)
		cout << "poor root; off by " << e << '\n';
	else if (e<-epsilon)
		cout << "poor root; off by " << e << '\n';
	return x;
}
void solve2()
{
	cout << "Please enter three floating-point numbers (a b c) to be used as the coefficients in a*x*x + b*x + c == 0: ";
	while (cin>>a>>b>>c) {
		if(a==0) {
			if (b==0)
				cout << "no root (since x isn't used)\n";
			else
				cout << "x == " << found(-c/b) << '\n';
		}
		else if (b==0) {
			double ca = -c/a;
			if (ca == 0)
				cout << "x==0\n";
			else if (ca < 0)
				cout << "no real roots\n";
			else
				cout << "two real roots: " << found(sqrt(ca)) << " and " << found(-sqrt(ca)) << '\n';
		}
		else {
			double sq = b*b-4*a*c;
			if (sq==0)
				cout << "one real root: " << found(-b/(2*a)) << '\n';
			else if (sq<0)
				cout << "no real roots\n";
			else
				cout << "two real roots: " << setprecision(12) << found((-b+sqrt(sq))/(2*a)) << " and " << found((-b-sqrt(sq))/(2*a)) << '\n';
		}
		cout << "please try again (enter a b c): ";
	}
}
int main()
try
{
	cout << "Do you want your results checked? (yes/no): ";
	string s;
	cin >> s;
	if (s=="no")
		solve();
	else if (s=="yes")
		solve2();
	else
		error("I don't understand the answer ",s);
	keep_window_open("~");
}
catch (runtime_error e) {
	cout << e.what() << '\n';
	keep_window_open("~");
}

