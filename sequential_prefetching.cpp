#include <iostream>

using namespace std;

//type 1
//type 2
//type 3
string dict[]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","forteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty","twenty one","twenty two","twenty three","twenty four","twenty five","twenty six","twenty seven","twenty eight","twenty nine","thirty"};

int cache_one[1000];
int cache_one_ptr=0;

bool cache_one_accessed[1000];
bool cache_one_being_accessed[1000];

bool cache_universal_accessed[1000];
bool cache_universal_fetched[1000];


void prefetch_one(int a)
{
  for(int i=0;i<1000;i++)
  {
    cache_one_being_accessed[i]=false;
  }
  cache_one_being_accessed[a]=true;
  if(!cache_one_accessed[a]){ cache_one_accessed[a]=true;
  cache_one[cache_one_ptr++]=a;
  if(!cache_one_accessed[a+1]) {cache_one_accessed[a+1]=true;
  cache_one[cache_one_ptr++]=a+1;}
}
  for(int i=0;i<cache_one_ptr;i++)
  {
    if(cache_one_being_accessed[cache_one[i]]) cout<<"-->";
    else cout<<"   ";
    cout<<dict[cache_one[i]]<<endl;
  }
  cout<<endl;
}

void prefetch_three(int a,int k)
{
  for(int i=0;i<1000;i++)
  {
    cache_one_being_accessed[i]=false;
  }
  cache_one_being_accessed[a]=true;
  for(int i=a;i<a+k;i++)
  {
    if(!cache_universal_fetched[i])
    {
      cache_one[cache_one_ptr++]=i;
      cache_universal_fetched[i]=true;
    }
  }
  cache_universal_accessed[a]=true;
  for(int i=0;i<cache_one_ptr;i++)
  {
    if(cache_one_being_accessed[cache_one[i]]) cout<<"-->";
    else cout<<"   ";
    if(cache_universal_accessed[cache_one[i]]) cout<<" 0 ";
    else cout<<" 1 ";
    cout<<dict[cache_one[i]]<<endl;
  }
  cout<<endl;
}




int main()
{
  for(int i=0;i<1000;i++)
  {
    cache_one_accessed[i]=false;
  }
  for(int i=0;i<1000;i++)
  {
    cache_one_being_accessed[i]=false;
  }
  for(int i=0;i<1000;i++)
  {
    cache_universal_accessed[i]=false;
  }
  for(int i=0;i<1000;i++)
  {
    cache_universal_fetched[i]=false;
  }

    cout<<"Enter 1 for type 1 prefetching"<<endl;
    cout<<"Enter 2 for type 2 prefetching"<<endl;
    cout<<"Enter 3 and K for type 3 prefetching"<<endl;
    int k;
    int type;
    cin>>type;
    if(type==3)
    {
      cout<<"K = ";
      cin>>k;
    }
    while(true)
    {
      cout<<"Enter the number to be prefetched"<<endl;
      cout<<"Enter -1 for Exiting"<<endl;
      int a;
      cin>>a;
      if(a==-1) break;
      else
      {
        if(type==1)
        {
          prefetch_one(a);
        }
        else if(type==2)
        {
          prefetch_three(a,2);
        }
        else
        {
          prefetch_three(a,k);
        }
      }
    }
  return 0;
}
