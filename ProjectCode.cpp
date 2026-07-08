#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    cout << fixed << setprecision(9);

    double a = 1.0;
    double b = 2.0;
    int n = 10;

    double h = (b - a) / n;

    // Arrays
    double x[11];
    double f[11];
    // Exact derivatives
    double exactfirst[11];
    double exactsecond[11];

    // First derivative methods
    double forward1[11];
    double backward1[11];
    double centered1[11];

    double forwarderror1[11];
    double backwarderror1[11];
    double centerederror1[11];

    // Second derivative methods
    double forward2[11];
    double backward2[11];
    double centered2[11];
    double forwarderror2[11];
    double backwarderror2[11];
    double centerederror2[11];



    for (int i = 0; i <= n; i++)
    {
        x[i] = a + i * h;

        f[i] = exp(x[i]) / x[i];


        exactfirst[i] = (exp(x[i]) * (x[i] - 1)) / pow(x[i], 2);

        exactsecond[i] = (exp(x[i]) * (pow(x[i], 2) - 2 * x[i] + 2)) / pow(x[i], 3);
    }


    // Forward Difference
    for (int i = 0; i < n; i++)
    {
        forward1[i] =
            (f[i + 1] - f[i]) / h;

        forwarderror1[i] =
            fabs(exactfirst[i] - forward1[i]);
    }

    // Backward Difference
    for (int i = 1; i <= n; i++)
    {
        backward1[i] =
            (f[i] - f[i - 1]) / h;

        backwarderror1[i] = fabs(exactfirst[i] - backward1[i]);

    }

    // Centered Difference
    for (int i = 1; i < n; i++)
    {
        centered1[i] = (f[i + 1] - f[i - 1]) / (2 * h);

        centerederror1[i] = fabs(exactfirst[i] - centered1[i]);
    }



    // Forward Second Difference
    for (int i = 0; i < n - 1; i++)

    {
        forward2[i] =
            (f[i + 2] - 2 * f[i + 1] + f[i]) / (h * h);

        forwarderror2[i] = fabs(exactsecond[i] - forward2[i]);



    }

    // Backward Second Difference
    for (int i = 2; i <= n; i++)
    {



        backward2[i] = (f[i] - 2 * f[i - 1] + f[i - 2]) / (h * h);

        backwarderror2[i] = fabs(exactsecond[i] - backward2[i]);
    }

    // Centered Second Difference
    for (int i = 1; i < n; i++)
    {
        centered2[i] = (f[i + 1] - 2 * f[i] + f[i - 1]) / (h * h);

        centerederror2[i] = fabs(exactsecond[i] - centered2[i]);




    }



    cout << "===============================================================\n";

    cout << "FIRST DERIVATIVE RESULTS\n";

    cout << "==============================================================\n\n";

    cout << "x\t"
        << "Exact\t\t"
        << "Forward\t"
        << "Error\t\t"
        << "Backward\t"
        << "Error\t\t"
        << "Centered\t"
        << "Error\n";

    cout << "========================================================================================================\n";


    for (int i = 0; i <= n; i++)
    {
        cout << x[i] << "\t";

        cout << exactfirst[i] << "\t";

        // Forward
        if (i < n)
        {
            cout << forward1[i] << "\t" << forwarderror1[i] << "\t";
        }
        else
        {

            cout << "---\t\t---\t\t";
        }

        // Backward
        if (i > 0)
        {
            cout << backward1[i] << "\t" << backwarderror1[i] << "\t";
        }
        else
        {

            cout << "---\t\t---\t\t";
        }

        // Centered
        if (i > 0 && i < n)
        {

            cout << centered1[i] << "\t" << centerederror1[i];
        }
        else
        {

            cout << "---\t\t---";
        }

        cout << endl;


    }



    cout << "\n\n";
    cout << "======================================================================\n";
    cout << "SECOND DERIVATIVE RESULTS\n";
    cout << "=====================================================================\n\n";

    cout << "x\t"
        << "Exact\t\t"
        << "Forward\t"
        << "Error\t\t"
        << "Backward\t"
        << "Error\t\t"
        << "Centered\t"
        << "Error\n";

    cout << "========================================================================================================\n";



    for (int i = 0; i <= n; i++)
    {


        cout << x[i] << "\t";

        cout << exactsecond[i] << "\t";

        // Forward
        if (i < n - 1)
        {


            cout << forward2[i] << "\t" << forwarderror2[i] << "\t";
        }
        else
        {


            cout << "---\t\t---\t\t";
        }

        // Backward
        if (i >= 2)
        {

            cout << backward2[i] << "\t" << backwarderror2[i] << "\t";
        }
        else
        {
            cout << "---\t\t---\t\t";
        }

        // Centered
        if (i >= 1 && i < n)
        {

            cout << centered2[i] << "\t" << centerederror2[i];
        }
        else
        {

            cout << "---\t\t---";
        }



        cout << endl;
    }



    double a2 = 0.0;

    double b2 = 4.0;

    int n2 = 40;

    double h2 = (b2 - a2) / n2;

    double x2[41];

    double y[41];



    for (int i = 0; i <= n2; i++)
    {
        x2[i] = a2 + i * h2;

        y[i] = x2[i] * exp(pow(x2[i], 2));
    }



    double exactintegral = 0.5 * (exp(16) - 1);


    double trapezoidal = y[0] + y[n2];

    for (int i = 1; i < n2; i++)
    {
        trapezoidal += 2 * y[i];
    }

    trapezoidal *= (h2 / 2);

    double trapezoidalError = fabs(exactintegral - trapezoidal);



    double simpson = y[0] + y[n2];

    for (int i = 1; i < n2; i += 2)
    {
        simpson += 4 * y[i];
    }

    for (int i = 2; i < n2; i += 2)
    {
        simpson += 2 * y[i];
    }

    simpson *= (h2 / 3);

    double simpsonerror = fabs(exactintegral - simpson);



    cout << "\n\n";
    cout << "==============================================================\n";
    cout << "FUNCTION VALUES FOR INTEGRATION\n";

    cout << "==============================================================\n\n";

    cout << "x\t\t\tf(x)\t\t\t\tN\n";

    for (int i = 0; i <= n2; i++)
    {
        cout << x2[i] << "\t\t"
            << y[i] << "\t"
            << i << endl;
    }



    cout << "\n\n";
    cout << "===================================================================\n";

    cout << "INTEGRATION RESULTS\n";
    cout << "========================================================================\n\n";



    cout << "Exact Integral = " << exactintegral << endl << endl;

    cout << "Composite Trapezoidal Rule\n";
    cout << "Approximation = " << trapezoidal << endl;



    cout << "Error = " << trapezoidalError << endl << endl;


    cout << "Composite Simpson Rule\n";
    cout << "Approximation = " << simpson << endl;

    cout << "Error = " << simpsonerror << endl;

    return 0;
}
