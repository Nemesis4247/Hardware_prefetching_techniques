#include <iostream>

using namespace std;

string dict[]={"zero","one","two","three","four","five","six","seven","eight",
"nine","ten","eleven","twelve","thirteen","forteen","fifteen","sixteen","seventeen"
,"eighteen","nineteen","twenty","twenty one","twenty two","twenty three","twenty four"
,"twenty five","twenty six","twenty seven","twenty eight","twenty nine","thirty"};

int cache_array[5];
int cache_ptr=0;

int buffer_1[4];
int buffer_2[4];
int buffer_3[4];

int ptr_1=0;
int ptr_2=0;
int ptr_3=0;

int cache=0;
int current_buffer=1;
bool stored[30];



void access(int a)
{
  cache=a;
  if(current_buffer==1)
  {
    for(int i=0;i<4;i++)
    {
      buffer_1[i]=a+1+i;
    }
    current_buffer++;
  }
  else if(current_buffer==2)
  {
    bool b=true;
    for(int i=0;i<4;i++)
    {
      if(buffer_1[i]==a)
      {
        for(int i=0;i<4;i++)
        {
          buffer_1[i]=a+1+i;
        }
        b=false;
        break;
      }
    }
    if(b)
    {
      for(int i=0;i<4;i++)
      {
        buffer_2[i]=a+1+i;
      }
      current_buffer++;
    }
  }
  else if(current_buffer==3)
  {
    bool b=true;
    for(int i=0;i<4;i++)
    {
      if(buffer_1[i]==a)
      {
        for(int i=0;i<4;i++)
        {
          buffer_1[i]=a+1+i;
        }
        b=false;
        break;
      }
    }
    if(b)
    {
      for(int i=0;i<4;i++)
      {
        if(buffer_2[i]==a)
        {
          for(int i=0;i<4;i++)
          {
            buffer_2[i]=a+1+i;
          }
          b=false;
          break;
        }
      }
    }
    if(b)
    {
      for(int i=0;i<4;i++)
      {
        buffer_3[i]=a+1+i;
      }
    }
  }
  else
  {
    bool b=true;
    for(int i=0;i<4;i++)
    {
      if(buffer_1[i]==a)
      {
        for(int i=0;i<4;i++)
        {
          buffer_1[i]=a+1+i;
        }
        b=false;
        break;
      }
    }
    if(b)
    {
      for(int i=0;i<4;i++)
      {
        if(buffer_2[i]==a)
        {
          for(int i=0;i<4;i++)
          {
            buffer_2[i]=a+1+i;
          }
          b=false;
          break;
        }
      }
    }
    if(b)
    {
      for(int i=0;i<4;i++)
      {
        if(buffer_3[i]==a)
        {
          for(int i=0;i<4;i++)
          {
            buffer_3[i]=a+1+i;
          }
          b=false;
          break;
        }
      }
    }
  }

}


void access_cache(int a)
{
  cout<<"Cache Status::::"<<endl;
  if(stored[a])
  {
    cout<<"Hit!!  "<<endl;
  }
  else
  {
    cout<<"Miss"<<endl;
    stored[a]=true;
    cache_array[cache_ptr++]=a;
    access(a);
  }

  for(int i=0;i<cache_ptr;i++)
  {
    if(cache_array[i]==a) cout<<"-->";
    else cout<<"  ";
    cout<<dict[cache_array[i]]<<endl;
  }
  cout<<endl;
  cout<<"Buffer 1   Buffer 2   Buffer 3"<<endl;
  for(int i=0;i<4;i++)
  {
    cout<<dict[buffer_1[i]]<<"           "<<dict[buffer_2[i]]<<"           "<<dict[buffer_3[i]]<<endl;
  }
  cout<<endl;
  cout<<endl;
}


int main()
{
  for(int i=0;i<4;i++)
  {
    buffer_1[i]=0;
  }
  for(int i=0;i<4;i++)
  {
    buffer_2[i]=0;
  }
  for(int i=0;i<4;i++)
  {
    buffer_3[i]=0;
  }
  for(int i=0;i<30;i++)
  {
    stored[i]=false;
  }
  while(true)
  {
    int u;
    cin>>u;
    if(u==-1) break;
    else access_cache(u);
  }

  return 0;
}
