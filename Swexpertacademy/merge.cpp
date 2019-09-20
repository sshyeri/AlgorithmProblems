#include <iostream>
using namespace std;
int p[10];
void merge(int l, int r, int m){
    int i = l; int j = m+1; int k = l;
    while(i<=m && j<=r){
        if(a[p[i]]<a[p[j]]) p[k++] = i++;
        else j++;
    }
    int t = i<m? i:j;
    while(k<=r) p[k++] = t++;
}
void part(int l, int r){
    if(l<r){
        int m = (l+r)/2;
        part(l, m);
        part(m, r);
        merge(l, r, m);
    }
}
int main(){
    int arr[10];
    int i = 10;
    while(i--) arr[i] = i;
    while(++i<10) cout<<arr[i];
}