#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char *argv[])
{
    char s1[1002], s2[1002], s3[1002];
    int l1, z, l2, x, l3, i, a, b, min, l;
    int n;
    int k;
    cin >> n;
    cout << "Case " << 1 << ":" << endl;  
    for ( i = 0; i <= 1001; i++)
      s1[i] = s2[i] = '0';
    for ( i = 0; i <= 1001; i++)
      s3[i] = '\0';
    cin >> s1;
    cin >> s2;
    cout << s1 << " + " << s2;
    l1 = strlen(s1);
    l2 = strlen(s2);
    for (i = 0; i < l1 / 2; i++)
      swap(s1[i] , s1[l1 - i - 1]);
    for (i = 0; i < l2 / 2; i++)
      swap(s2[i] , s2[l2 - i - 1]);
    //cout << s1 << endl << s2;
    if (l1 > l2)
    {  
      l = l1;
      s2[l2] = '0';
      s2[l1] = '\0';
    }
    else
    {
        l = l2;
        s1[l1] = '0';
        s1[l2] = '\0';
    }  
    //cout << s1 << endl << s2 << endl;
    //system("pause");
    for (i = 0, x = 0; i < l; i++)
    {  
      a = s1[i] - '0';
      b = s2[i] - '0';
      s3[i] = (a + b + x) % 10 + '0';
      z = (a + b + x) / 10;
      x = z;    
    }
    if (x)
      s3[i++] = '1';
    l3 = strlen(s3);
    for (i = 0; i < l3 / 2; i++)
      swap(s3[i] , s3[l3 - i - 1]);
    cout << " = " << s3 << endl;
    for (k = 2; k <= n; k++)
    {
    cout << endl << "Case " << k << ":" << endl;  
    for ( i = 0; i <= 1001; i++)
      s1[i] = s2[i] = '0';
    for ( i = 0; i <= 1001; i++)
      s3[i] = '\0';
    cin >> s1;
    cin >> s2;
    cout << s1 << " + " << s2;
    l1 = strlen(s1);
    l2 = strlen(s2);
    for (i = 0; i < l1 / 2; i++)
      swap(s1[i] , s1[l1 - i - 1]);
    for (i = 0; i < l2 / 2; i++)
      swap(s2[i] , s2[l2 - i - 1]);
    //cout << s1 << endl << s2;
    if (l1 > l2)
    {  
      l = l1;
      s2[l2] = '0';
      s2[l1] = '\0';
    }
    else
    {
        l = l2;
        s1[l1] = '0';
        s1[l2] = '\0';
    }  
    //cout << s1 << endl << s2 << endl;
    //system("pause");
    for (i = 0, x = 0; i < l; i++)
    {  
      a = s1[i] - '0';
      b = s2[i] - '0';
      s3[i] = (a + b + x) % 10 + '0';
      z = (a + b + x) / 10;
      x = z;    
    }
    if (x)
      s3[i++] = '1';
    l3 = strlen(s3);
    for (i = 0; i < l3 / 2; i++)
      swap(s3[i] , s3[l3 - i - 1]);
    cout << " = " << s3 << endl;
    }
    //system("PAUSE");
    return EXIT_SUCCESS;
}