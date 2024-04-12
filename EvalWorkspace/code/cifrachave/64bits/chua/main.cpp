



#include <stdio.h>

#include <process.h>

#include "math.h"



#define h       1.0 * pow(10, -6)

#define C1      10.0 * pow(10, -9)

#define C2      100.0 * pow(10, -9)

#define L       19.0 * pow(10, -3)

#define R       1800.0

#define m0     -0.37 * pow(10, -3)

#define m1     -0.68 * pow(10, -3)

#define Bp      1.1

#define eq1     1.0 / (10.0 * pow(10, -9))

#define eq2     1.0 / (100.0 * pow(10, -9))

#define eq3    -1.0 / (19.0 * pow(10, -3))

#define yo     -0.2

#define zo      0.0



 double K1 = zo;

 double K2 = zo;

 double K3 = zo;

 double K4 = zo;

 double L1 = zo;

 double L2 = zo;

 double L3 = zo;

 double L4 = zo;

 double M1 = zo;

 double M2 = zo;

 double M3 = zo;

 double M4 = zo;



double xd     = zo;

double yd     = zo;

double zd     = zo;

double id     = zo;

double xeqabs = zo;

double xeq    = zo;



double x = zo;

double y = yo;

double z = zo;





double x2 = zo;

double y2 = yo;

double z2 = zo;

//int A[90000];



FILE* stream1;

void ccs(double x0,const int loop, const char namepath[])
{

fopen_s(&stream1, namepath, "w");
if (stream1 == 0) {
	printf("deuruimglr");
}
else { ; }

  x  = x0;

 x2 = x0;

 for (int i = 0; i < loop; i++) {





		xeqabs = fabs((x - x2) / 2);

		xeq = log(xeqabs);



 xeq =fabs( xeq * pow(10,8));

fprintf(stream1, "%lld \n",  ((long long int)xeq)%256) ;




		K1 = 0;

		K2 = 0;

		K3 = 0;

		K4 = 0;

		L1 = 0;

		L2 = 0;

		L3 = 0;

		L4 = 0;

		M1 = 0;

		M2 = 0;

		M3 = 0;

		M4 = 0;



		xd = 0;

		yd = 0;

		zd = 0;







		if (x > Bp) {

			id = (m0 * x + Bp * (m1 - m0));

		}

		else if (x < -Bp) {

			id = (m0 * x + Bp * (m0 - m1));

		}

		else {

			id = (m1 * x);

		}





		K1 = eq1 * ((y - x) / R - id);

		L1 = eq2 * ((x - y) / R + z);

		M1 = eq3 * y;





		xd = x + h * (0.5) * K1;

		yd = y + h * (0.5) * L1;

		zd = z + (0.5) * h * M1;







		if (xd > Bp) {

			id = m0 * xd + Bp * (m1 - m0);

		}

		else if (xd < (-Bp)) {

			id = m0 * xd + Bp * (m0 - m1);

		}

		else {

			id = m1 * xd;

		}



		K2 = eq1 * ((yd - xd) / R - id);

		L2 = eq2 * ((xd - yd) / R + zd);

		M2 = eq3 * yd;





		xd = x + h * (0.5) * K2;

		yd = y + h * (0.5) * L2;

		zd = z + (0.5) * h * M2;



		if (xd > Bp) {

			id = m0 * xd + Bp * (m1 - m0);

		}

		else if (xd < (-Bp)) {

			id = m0 * xd + Bp * (m0 - m1);

		}

		else {

			id = m1 * xd;

		}

		K3 = eq1 * ((yd - xd) / R - id);

		L3 = eq2 * ((xd - yd) / R + zd);

		M3 = eq3 * yd;





		xd = x + h * K3;

		yd = y + h * L3;

		zd = z + h * M3;







		if (xd > Bp) {

			id = m0 * xd + Bp * (m1 - m0);

		}

		else if (xd < (-Bp)) {

			id = m0 * xd + Bp * (m0 - m1);

		}

		else {

			id = m1 * xd;

		}



		K4 = eq1 * ((yd - xd) / R - id);

		L4 = eq2 * ((xd - yd) / R + zd);

		M4 = eq3 * yd;











		x = x + h * (1.0 / 6.0) * (K1 + (2.0) * K2 + (2.0) * K3 + K4);

		y = y + h * (1.0 / 6.0) * (L1 + (2.0) * L2 + (2.0) * L3 + L4);

		z = z + h * (1.0 / 6.0) * (M1 + (2.0) * M2 + (2.0) * M3 + M4);

		



		K1 = 0;

		K2 = 0;

		K3 = 0;

		K4 = 0;

		L1 = 0;

		L2 = 0;

		L3 = 0;

		L4 = 0;

		M1 = 0;

		M2 = 0;

		M3 = 0;

		M4 = 0;



		xd = 0;

		yd = 0;

		zd = 0;





		if (x2 > Bp) {

			id = (m0 * x2 + Bp * (m1 - m0));

		}

		else if (x2 < -Bp) {

			id = (m0 * x2 + Bp * (m0 - m1));

		}

		else {

			id = (m1 * x2);

		}





		K1 = eq1 * (y2 / R - x2 / R - id);

		L1 = eq2 * ((x2 - y2) / R + z2);

		M1 = eq3 * y2;





		xd = x2 + h * (0.5) * K1;

		yd = y2 + h * (0.5) * L1;

		zd = z2 + (0.5) * h * M1;







		if (xd > Bp) {

			id = m0 * xd + Bp * (m1 - m0);

		}

		else if (xd < (-Bp)) {

			id = m0 * xd + Bp * (m0 - m1);

		}

		else {

			id = m1 * xd;

		}



		K2 = eq1 * (yd / R - xd / R - id);

		L2 = eq2 * ((xd - yd) / R + zd);

		M2 = eq3 * yd;



		xd = x2 + h * (0.5) * K2;

		yd = y2 + h * (0.5) * L2;

		zd = z2 + (0.5) * h * M2;



		if (xd > Bp) {

			id = m0 * xd + Bp * (m1 - m0);

		}

		else if (xd < (-Bp)) {

			id = m0 * xd + Bp * (m0 - m1);

		}

		else {

			id = m1 * xd;

		}

		K3 = eq1 * (yd / R - xd / R - id);

		L3 = eq2 * ((xd - yd) / R + zd);

		M3 = eq3 * yd;







		xd = x2 + h * K3;

		yd = y2 + h * L3;

		zd = z2 + h * M3;







		if (xd > Bp) {

			id = m0 * xd + Bp * (m1 - m0);

		}

		else if (xd < (-Bp)) {

			id = m0 * xd + Bp * (m0 - m1);

		}

		else {

			id = m1 * xd;

		}



		K4 = eq1 * (yd / R - xd / R - id);

		L4 = eq2 * ((xd - yd) / R + zd);

		M4 = eq3 * yd;











		x2 = x2 + h * (1.0 / 6.0) * (K1 + (2.0) * K2 + (2.0) * K3 + K4);

		y2 = y2 + h * (1.0 / 6.0) * (L1 + (2.0) * L2 + (2.0) * L3 + L4);

		z2 = z2 + h * (1.0 / 6.0) * (M1 + (2.0) * M2 + (2.0) * M3 + M4);

}
 fclose(stream1);
     y =yo;

	z = zo;

	y2 = yo;

	z2 = zo;

}



int main(){

ccs(0.802296938300132822519117326010,90536,"../../../../../mod/4.1.01.fdmod");
ccs(0.801303749084472660690892098501,90536,"../../../../../mod/4.1.02.fdmod");
ccs(-0.805457883477211034062293038005,90536,"../../../../../mod/4.1.03.fdmod");
ccs(0.804342848658561759833673932008,90536,"../../../../../mod/4.1.04.fdmod");
ccs(-0.805393688082695069496708129009,90536,"../../../../../mod/4.1.05.fdmod");
ccs(-0.805045871138572732839122636506,90536,"../../../../../mod/4.1.06.fdmod");
ccs(-0.806869137287139936987045985006,90536,"../../../../../mod/4.1.07.fdmod");
ccs(-0.806532230377197345561057773011,90536,"../../../../../mod/4.1.08.fdmod");
ccs(0.804030898511409852780218443513,287144,"../../../../../mod/4.2.01.fdmod");
ccs(-0.805063066929578852182203263510,287144,"../../../../../mod/4.2.03.fdmod");
ccs(-0.806999176144599927873457545502,287144,"../../../../../mod/4.2.05.fdmod");
ccs(0.804891989231109716840251167014,287144,"../../../../../mod/4.2.06.fdmod");
ccs(0.804695954024791770820002057008,287144,"../../../../../mod/4.2.07.fdmod");
ccs(0.804990625977516249811571924511,90536,"../../../../../mod/5.1.09.fdmod");
ccs(-0.805488557219505407758219917014,90536,"../../../../../mod/5.1.10.fdmod");
ccs(-0.807560696601867689103926295502,90536,"../../../../../mod/5.1.11.fdmod");
ccs(-0.807264854311943058640110848501,90536,"../../../../../mod/5.1.12.fdmod");
ccs(-0.808824803829193195170432773011,90536,"../../../../../mod/5.1.13.fdmod");
ccs(0.804080856442451530341486432008,90536,"../../../../../mod/5.1.14.fdmod");
ccs(0.804811609238386238551754559012,287144,"../../../../../mod/5.2.08.fdmod");
ccs(-0.807053584158420656002874693513,287144,"../../../../../mod/5.2.09.fdmod");
ccs(0.804445371329784442160359958507,287144,"../../../../../mod/5.2.10.fdmod");
ccs(0.803476856537163275362445347128,1073576,"../../../../../mod/5.3.01.fdmod");
ccs(0.803241974078118814439619654877,1073576,"../../../../../mod/5.3.02.fdmod");
ccs(0.804184141308069255771329153504,287144,"../../../../../mod/7.1.01.fdmod");
ccs(-0.806849021017551515377874693513,287144,"../../../../../mod/7.1.02.fdmod");
ccs(-0.805171278417110447556126473501,287144,"../../../../../mod/7.1.03.fdmod");
ccs(0.804535877257585574362508396007,287144,"../../../../../mod/7.1.04.fdmod");
ccs(0.804155990630388339823753085511,287144,"../../../../../mod/7.1.05.fdmod");
ccs(0.803534472882747707878081655508,287144,"../../../../../mod/7.1.06.fdmod");
ccs(0.804228071421384860251180271007,287144,"../../../../../mod/7.1.07.fdmod");
ccs(0.804968284815549939281709157513,287144,"../../../../../mod/7.1.08.fdmod");
ccs(0.804906392246484747587942365499,287144,"../../../../../mod/7.1.09.fdmod");
ccs(0.804659099429845814377415536001,287144,"../../../../../mod/7.1.10.fdmod");
ccs(0.801270077936351299285888671875,1073576,"../../../../../mod/7.2.01.fdmod");
ccs(-0.805313914418220533342207545502,90536,"../../../../../mod/Boat.fdmod");
ccs(0.804637603759765673849813083507,90536,"../../../../../mod/Cman.fdmod");
ccs(-0.805390023589134251835730538005,90536,"../../../../../mod/House.fdmod");
ccs(0.803854550123214717238795401499,90536,"../../../../../mod/Lena.fdmod");
ccs(0.804810326695442279643089023011,90536,"../../../../../mod/Pepper.fdmod");
ccs(-0.805066717416048072131218305003,287144,"../../../../../mod/boat.512.fdmod");
ccs(0.804962434470653631635173042014,287144,"../../../../../mod/gray21.512.fdmod");
ccs(-0.808864848315715811999382367503,287144,"../../../../../mod/ruler.512.fdmod");
 }