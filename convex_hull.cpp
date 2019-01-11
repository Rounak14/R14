#include <bits/stdc++.h>
using namespace std;

struct point
{
  int x,y;
};

point p0;

void swap(point &p1,point &p2)
{
  point temp=p1;
  p1=p2;
  p2=temp;
}

point nexttop(stack<point> &s)
{
  point p=s.top();
  s.pop();
  point res=s.top();
  s.push(p);
  return res;
}

int distance(point p1,point p2)
{
  int d=((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
  return d;
}
int orientation(point p,point q,point r)
{
  int val=(q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
  if(val==0)
    return 0;
  if(val>0)
  {
    return 1;
  }
  else
  {
    return 2;
  }
}
int compare(const void *vp1,const void *vp2)
{
  point *p1=(point *)vp1;
  point *p2=(point *)vp2;
  int o=orientation(p0,*p1,*p2);

  if(o==0)
  {
    if(distance(p0,*p2)>=distance(p0,*p1))
    {
      return -1;
    }
    else
    {
      return 1;
    }
  }
  if(o==2)
  {
    return -1;
  }
  else
  {
    return 1;
  }
}
void convexhull(point points[],int n)
{
  int min=0,ymin=points[0].y;
  for(int i=0;i<n;i++)
  {
    int y=points[i].y;
    if(y<ymin||(y==ymin&&points[i].x<points[min].x))
    {
      ymin=points[i].y;
      min=i;
    }
  }
  swap(points[0],points[min]);
  p0=points[0];
  qsort(&points[1], n-1, sizeof(point), compare);

  int m=1;
  for(int i=0;i<n;i++)
  {
    while(i<n-1&&orientation(p0,points[i],points[i+1])==0)
    {
      i++;
    }
    points[m]=points[i];
    m++;
  }
  if(m<3)return;

  stack<point> s;
  s.push(points[0]);
  s.push(points[1]);
  s.push(points[2]);

  for(int i=3;i<m;i++)
  {
    while(orientation(nexttop(s),s.top(),points[i])!=2)
    {
      s.pop();
    }
    s.push(points[i]);
  }

  while(!s.empty())
  {
    point p = s.top();
    cout << "(" << p.x << ", " << p.y <<")" << endl;
    s.pop();
  }
}

int main()
{
  int number_points;
  cout<<"Enter the number of points : ";
  cin>>number_points;
  point *points=new point[number_points];
  for(int i=0;i<number_points;i++)
  {
    cout<<"Point["<<i+1<<"] : ";
    cin>>points[i].x>>points[i].y;
  }
  convexhull(points,number_points);
}
