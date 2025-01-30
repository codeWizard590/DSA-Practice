#include<bits/stdc++.h>
using namespace std;

class Gcd{
    public :
    // the idea is to get the mod of smallest number . as whatever is present in smaller 
    // example x and y => x=60 and y=36 
    // 36%36 , 36%35 ,36%34 , --- >  60%36 , 60%35 --> 60%12 =0 /5 , 36%12 =0 /4
    // will check when going from the back if the smallest number and the largest number are 
    // divisible by any number between 36 to 0 -> going backwards is important as we need to have the 
    // highest common factor ..
        int gcdOfTwo_BF(int x,int y){
            int result=min(x,y);
            while(result>=0){
                if(x%result==0&&y%result==0){
                    break;
                }
                result--;
            }
            return result;
        }

        // using eucledian approach 
        // worst case time complexity -> O(min(a,b));
        int gcdOfTwo_Euc(int x,int y){
            //int expected_OP=__gcd(x,y);
            if(x==0){
                return y;
            }
            if(y==0){
                return x;
            }
            if(x==y){
                return x;
            }
            if(x>y){
                return gcdOfTwo_Euc(x-y,y);
            }
            return gcdOfTwo_Euc(x,y-x);

        }

        // further trying to optimise euclidean method using division
        int gcdOfTwo_Div(int x,int y){
            if(x==0){
                return y;
            }
            if(y==0){
                return x;

            }
            if(x==y){
                return x;
            }
            if(x>y){
                if(x%y==0){
                    return y;
                }
                return gcdOfTwo_Div(x-y,y);
            }
            else{
                if(y%x==0){
                    return x;
                }
                return gcdOfTwo_Div(x,y-x);
            }
        }
        // last approach where w edirectly take the mod 
        int gcdOfTwo_BA(int x,int y){
            return y==0?x:gcdOfTwo_BA(y,x%y);
        }
        int gcdOfTwo_BA2(int x,int y){
            return x==0?y:gcdOfTwo_BA(y%x,x);
        }

};

class GcdArr{
    public :
        int findGcdAndInclude(int x,int y){
            return y==0?x:findGcdAndInclude(y,x%y);
        }

        int gcdOfArr(int arr[],int n){
            // gcd 36 ,60 -> 
            int result=arr[0];
            for(int i=1;i<n;i++){
               result=findGcdAndInclude(result,arr[i]);
               if(result==1){
                return result;
               } 
            }
            return result;
        }
};

class Lcm:GcdArr{
    public :
        // we know that the product of two numbers is equal to hcf and lcm of those numbers 
        
        int lcm_TwoNos(int x,int y){
            return ((x*y)/findGcdAndInclude(x,y));
        }

        int lcm_array(int arr[],int n){
            int temp=arr[0];
            for(int i=0;i<n;i++){
                 
            }
        }
};
int main(){
    Gcd gcd;
    int x= gcd.gcdOfTwo_BF(36,60);
    cout<<"GCD of two numbers using brute force : "<<x<<endl;
    int y=gcd.gcdOfTwo_Euc(36,60);
    cout<<"GCD using subtraction is :"<<y<<endl;
    int z=gcd.gcdOfTwo_Div(36,60);
    cout<<"GCD using div is :"<<z<<endl;
    int l=gcd.gcdOfTwo_BA(36,60);
    cout<<"GCD using a%b is :"<<l<<endl;
    int b=gcd.gcdOfTwo_BA2(60,36);
    cout<<"GCD using b%a is :"<<b<<endl;
    GcdArr gcdarr;
    int arr[]={36,60,30,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int j=gcdarr.gcdOfArr(arr,n);
    cout<<"array gcd is : "<<j<<endl;
    Lcm lcm;
    int lcms=lcm.lcm_TwoNos(15,20);
    cout<<"LCM is :"<<lcms<<endl;
    int lcmarr=lcm.lcm_array(arr,n);
    cout<<"lcm arr: "<<lcmarr<<endl;
}