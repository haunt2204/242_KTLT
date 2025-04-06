#include <iostream>
#include <fstream>
using namespace std;

void pushBackArr(int *&a, int &n, int x){
    if(a==NULL){
        n = 1;
        a = new int[n];
        a[0] = x;
    }else{
        int *newArr = new int[n+1];
        
        for(int i=0; i<n;i++){
            newArr[i] = a[i];
        }
        
        newArr[n++] = x;
        
        delete [] a;
        
        a=newArr;
    }
}

int main(){
    int *a=NULL, n=0;
    
    ifstream inFile("data.txt");
//    inFile.open("data.txt",ios::in);
    
    if(inFile.is_open()){
        //inFile>>n;//n=5
        
        //a = new int[n];
        
        while(!inFile.eof()){
            int tmp;

            inFile>>tmp;
            
            pushBackArr(a, n, tmp);
        }
        
        for(int i=0; i<n;i++){
            cout << a[i] << " ";
        }
        
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(a[j]>a[i])
                    swap(a[j], a[i]);
            }
        }
        
        ofstream outFile;
        outFile.open("sortedList.txt", ios::app);
        
        if(outFile.is_open()){
            outFile<<endl;
            for(int i=0; i<n;i++){
                outFile << a[i] << " ";
            }
            
            outFile.close();
        }
        
        delete [] a;
        inFile.close();
    }
    
    return 0;
}
