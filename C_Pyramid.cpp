#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-6;

double slantHeight(double b, double h)
{
    return sqrt((b / 2) * (b / 2) + h * h);
}

double surfaceArea(double b, double h)
{
    double s = slantHeight(b, h);
    return b * b + 2 * b * s;
}

double volume(double b, double h)
{
    return (1.0 / 3.0) * b * b * h;
}

double maxVolume(double fixedSurfaceArea)
{
    double bestVolume = 0.0;
    for (double b = 0.01; b < 1000; b += 0.01)
    {
        double low = 0, high = 1000;
        while (high - low > EPS)
        {
            double h = (low + high) / 2;
            double currentSurfaceArea = surfaceArea(b, h);

            if (currentSurfaceArea > fixedSurfaceArea)
            {
                high = h;
            }
            else
            {
                low = h;
            }
        }

        double h = (low + high) / 2;
        double currentVolume = volume(b, h);

        if (surfaceArea(b, h) <= fixedSurfaceArea)
        {
            bestVolume = max(bestVolume, currentVolume);
        }
    }
    return bestVolume;
}

int main()
{

    double fixedSurfaceArea;
    cin >> fixedSurfaceArea;

    double maxVol = maxVolume(fixedSurfaceArea);
    cout << " " << fixed << setprecision(4) << maxVol << endl;

    return 0;
}
