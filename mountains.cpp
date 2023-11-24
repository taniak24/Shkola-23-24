#include <iostream>
#include <ctime>

using namespace std;

int longest_word(string arr[], int n)
{
    string len = arr[0];

    for(int i = 0; i < n; i++)
    {
        if(arr[i].length() > len.length())
        {
            len = arr[i];
        }
    }

    return len.length();
}

string spaces(string word, int lw)
{
    int len = word.length();
    string space = "";

    for(int i = len; i < lw; i++)
    {
       space+= " ";
    }

    return space;
}

void rand_peak(string n[], int h[], int ri, int ri2)
{
    if(h[ri] == h[ri2])
    {
        ri = rand() % 10;
        ri2 = rand() % 10;
    }

    if(h[ri] > h[ri2])
    {
        cout << n[ri] << " is higher than " << n[ri2] << endl;
    }
    else
    {
        cout << n[ri] << " is shorter than " << n[ri2] << endl;
    }
}

void fill_array(int ri, int ri2)
{
    int row = 20;
    int col = 60;

    int start_index = col - 20;

    ///delete maybe
    /*
    int sh_gap = 3;
    int bh_gap = 5;*/

    char peak[row][col];

    int short_height = row - 5;
    int long_height = row - 10;

    ///fill array
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(i == row - 1)
            {
                peak[i][j] = '*';
            }
            else
            {
                peak[i][j] = ' ';
            }
        }
    }

    ///draw peaks
   for(int i = 0; i < row - 1; i++)
    {
        for(int j = 0; j < col - 1; j++)
        {
            ///shorter
            if((i + j == row - 1) && i >= short_height)
            {
                peak[i][j] = '/';
            }
            if((i - j == row/2) && i >= short_height)
            {
                peak[i][j] = '\\';
            }
            ///higher mountain
            if((i + j == row - 1) && i >= long_height)
            {
                peak[i][j + 15] = '/';
            }
            if((i - j == row/2) && i >= long_height)
            {
                peak[i][j + 25] = '\\';
            }
        }
    }

    ///print the array
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout << peak[i][j];
        }
        cout << endl;
    }
}


int main()
{
    srand(time(0));

    const int N = 10;

    string mountains[N] = {"Rila", "Pirin", "Stara planina", "Vitosha", "Osogovo", "Slavqnka", "Rodopi", "Belasica", "Rui", "Sredna gora"};
    string peaks[N] = {"Musala", "Vihren", "Botev", "Cherni vruh", "Ruen", "Gocev vruh", "Golqm Perelik", "Radomir", "Rui", "Bogdan"};
    int height[N] = {2925, 2914, 2376, 2290, 2251, 2212, 2191, 2029, 1706, 1604};


    ///find the longest word
    int longest_w_m = longest_word(mountains, N);
    int longest_w_p = longest_word(peaks, N);

    ///rand index for the peaks
    int rand_index = rand() % 10;
    int rand_index2 = rand() % 10;

    /*
    ///height for fill array
    int short_height = row - 5;
    int long_height = row - 10;*/


    for(int i = 0; i < N; i++)
    {
        cout << mountains[i] << spaces(mountains[i], longest_w_m) << " | " << peaks[i] << spaces(peaks[i], longest_w_p) << " | " << height[i] << endl;
    }

    cout << endl;
    rand_peak(peaks, height, rand_index, rand_index2);

    cout << endl;
    fill_array(rand_index, rand_index2);


    return 0;
}
