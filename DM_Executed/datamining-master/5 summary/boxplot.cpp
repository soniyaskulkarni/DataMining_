//%%writefile boxplot.cpp
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int median(vector<double> arr)
{
    sort(arr.begin(), arr.end());
    if (arr.size() % 2)
    {
        return arr[arr.size() / 2];
    }
    else
    {
        return (arr[arr.size() / 2 - 1] + arr[arr.size() / 2]) / 2;
    }
}

void print(vector<double> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<double> vect;

    fstream fin;

    fin.open("input.csv");

    vector<string> row;
    string line, word, temp;

    while (fin.peek() != EOF)
    {

        row.clear();

        getline(fin, line);

        stringstream s(line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        if (row[0] != "sr.no.")
        {
            double num = stod(row[1]);
            vect.push_back(num);
        }
    }

    fin.close();

    sort(vect.begin(), vect.end());

    vector<double> half1, half2;
    double Q2 = median(vect);

    if (vect.size() % 2)
    {
        for (int i = 0; i < vect.size(); i++)
        {
            if (i <= vect.size() / 2)
            {
                half1.push_back(vect[i]);
            }
            else
            {
                half2.push_back(vect[i]);
            }
        }
    }

    else
    {
        for (int i = 0; i < vect.size(); i++)
        {
            if (i <= vect.size() / 2 - 1)
            {
                half1.push_back(vect[i]);
            }
            else
            {
                half2.push_back(vect[i]);
            }
        }
    }

    double Q1 = median(half1);
    double Q3 = median(half2);
    double IQR = Q3 - Q1;
    double LL = Q1 - 1.5 * IQR;
    double UL = Q3 + 1.5 * IQR;
    double MIN, MAX;

    int mini, maxi;

    for (int j = 0; j < vect.size(); j++)
    {
        if (vect[j] > LL)
        {
            MIN = vect[j];
            mini = j;
            break;
        }
    }
    for (int j = 0; j < vect.size(); j++)
    {
        if (vect[vect.size() - j - 1] < UL)
        {
            MAX = vect[vect.size() - j - 1];
            maxi = vect.size() - j - 1;
            break;
        }
    }

    vector<double> OUTLIERS;
    for (int j = 0; j < vect.size(); j++)
    {
        if (j < mini || j > maxi)
        {
            OUTLIERS.push_back(vect[j]);
        }
    }

    cout << "\nQ1 " << Q1 << "\nQ2 " << Q2 << "\nQ3 " << Q3 << "\nIQR " << IQR << "\nLL "
         << LL << "\nUL " << UL << "\nMIN " << MIN << "\nMAX " << MAX << endl
         << "Outliers: ";
    for (int k = 0; k < OUTLIERS.size(); k++)
    {
        if (k==OUTLIERS.size()-1)
        {
          cout << OUTLIERS[k];
          break;
        }
      cout << OUTLIERS[k] << ",";
    }
    cout << endl;

    fstream fout("output.txt",ios::app);

    fout << "\nQ1: \t " << Q1 << "\nQ2: \t " << Q2 << "\nQ3: \t " << Q3 << "\nIQR: \t " << IQR
         << "\nLL: \t " << LL << "\nUL: \t " << UL << "\nMIN: \t " << MIN << "\nMAX: \t " << MAX << endl
         << "Outliers: ";
    for (int k = 0; k < OUTLIERS.size(); k++)
    {
      fout << OUTLIERS[k] << ",";
    }
    fout<<"\n";

    fout.close();

    return 0;
}