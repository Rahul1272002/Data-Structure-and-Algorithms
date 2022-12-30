#include <iostream>
using namespace std;
class Chart
{
public:
    int *completionTime, *TurnaroundTime, *waitingTime;
    Chart(int n)
    {
        completionTime = new int(n);
        TurnaroundTime = new int(n);
        waitingTime = new int(n);
    }
};
void printDataProcess(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}
void cTCalculation(int *arr, int n, int *BT)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += BT[i];
        arr[i] = s;
    }
}
void TATCalculation(int *Tat, int n, int *ct, int *at)
{
    for (int i = 0; i < n; i++)
    {
        Tat[i] = ct[i] - at[i];
    }
}
float waittime(int *Wt, int *Tat, int *Bt, int n)
{
    float avg, s = 0;
    for (int i = 0; i < n; i++)
    {
        Wt[i] = Tat[i] - Bt[i];
        s += Wt[i];
    }
    return s / 3.0;
}
int main()
{
    cout << "Enter no of Process:";
    int n;
    cin >> n;
    Chart process(n);
    int *ArrivalTime, *BrustTime;
    ArrivalTime = new int(n);
    BrustTime = new int(n);
    int v1, v2;
    cout << "Enter Arrival Time and Brust Time" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> v1 >> v2;
        ArrivalTime[i] = v1;
        BrustTime[i] = v2;
    }
    cout << "ArrivalTime" << endl;
    printDataProcess(ArrivalTime, n);

    cout << "Brust Time" << endl;
    printDataProcess(BrustTime, n);

    cTCalculation(process.completionTime, n, BrustTime);
    cout << "CompletionTime" << endl;
    printDataProcess(process.completionTime, n);

    cout << "TurnaroundTime" << endl;
    TATCalculation(process.TurnaroundTime, n, process.completionTime, ArrivalTime);
    printDataProcess(process.TurnaroundTime, n);

    cout << "WaitTime" << endl;
    float x = waittime(process.waitingTime, process.TurnaroundTime, BrustTime, n);
    printDataProcess(process.waitingTime, n);

    cout << "Average of waiting time:" << x;
    return 0;
}