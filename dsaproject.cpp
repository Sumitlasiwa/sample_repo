#include <iostream>
using namespace std;
bool issafe(int** arr,int x,int y,int n,int** vis){
    if(x>=0 && y>=0 && x<n && y<n && arr[x][y]==1 && !vis[x][y])
        return true;
    else
        return false;
}
bool solve(int** arr,int x,int y,int n,int** solnArr,int** vis){
    if((x==(n-1)) && (y==(n-1))){
        solnArr[x][y]=1;
        return true;
    }
    if(issafe(arr,x,y,n,vis)){
        solnArr[x][y]=1;
        vis[x][y]=1;
        if(solve(arr,x+1,y,n,solnArr,vis)){//down
            return true;
        }
        if(solve(arr,x,y-1,n,solnArr,vis)){//left
            return true;
        }
        if(solve(arr,x,y+1,n,solnArr,vis)){//right
            return true;
        }
        if(solve(arr,x-1,y,n,solnArr,vis)){//Up
            return true;
        }
        solnArr[x][y]=0;  //backtracking
        vis[x][y]=0;
        return false;
    }
    return false;        
}
int main(){
    int n;
    cout<<"Enter size: ";
    cin>>n;
    int** arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
    } 
    cout<<"Enter maze of "<<n<<"*"<<n<<" : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    cout<<endl;   
    int** solnArr=new int *[n];
    for(int i=0;i<n;i++){
        solnArr[i]=new int[n];
    } 
    
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){    //initializing soln arr with 0
            solnArr[i][j]=0;
        }
    }
    int** visArr=new int *[n];
    for(int i=0;i<n;i++){
        visArr[i]=new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visArr[i][j]=0;
        }
      }
    cout<<"Solved maze: "<<endl;
    if(solve(arr,0,0,n,solnArr,visArr)){
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<solnArr[i][j]<<" ";
        }cout<<endl;
    }
    }
    //dellocating 2d array
    for(int i=0;i<n;i++)
        delete[] arr[i];
    delete[] arr;

    for(int i=0;i<n;i++)
        delete[] solnArr[i];
    delete[] solnArr;

    for(int i=0;i<n;i++)
        delete[] visArr[i];
    delete[] visArr;
    return 0;
}

