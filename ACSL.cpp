//author Kewen Zhao

using namespace std;
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>

struct Point{
  int x,y;
  Point(int x, int y): x(x),y(y){}
};

int grid[4][4];

string remove(vector<Point> v){
  vector<string> vec;
  string ans="";
  for(Point p : v){
    int px = p.x, py = p.y;
    if(px == 0){
      vec.push_back("B");
      vec.push_back("~D");
    }
    if(px == 1){
      vec.push_back("B");
      vec.push_back("D");
    }
    if(px == 2){
      vec.push_back("~B");
      vec.push_back("D");
    }
    if(px == 3){
      vec.push_back("~B");
      vec.push_back("~D");
    }
    if(py == 0){
      vec.push_back("A");
      vec.push_back("~C");
    }
    if(py == 1){
      vec.push_back("A");
      vec.push_back("C");
    }
    if(py == 2){
      vec.push_back("~A");
      vec.push_back("C");
    }
    if(py == 3){
      vec.push_back("~A");
      vec.push_back("~C");
    }
    grid[px][py] = 0;
  }
  int pos,neg;
  pos = 0, neg = 0;
  for(string s: vec){
    if(s == "A") pos++;
    if( s == "~A") neg++;
  }
  if(pos!=0 && neg == 0) ans = ans + "A";
  else if(pos==0 && neg != 0) ans = ans + "~A";

  pos = 0, neg = 0;
  for(string s: vec){
    //printf("%s\n",&s[0] );
    if(s == "B") pos++;
    if( s == "~B") neg++;
  }
  //printf("%d %d\n",pos,neg );
  if(pos!=0 && neg == 0) ans = ans + "B";
  else if(pos==0 && neg != 0) ans = ans + "~B";

  pos = 0, neg = 0;
  for(string s: vec){
    if(s == "C") pos++;
    if( s == "~C") neg++;
  }
  if(pos!=0 && neg == 0) ans = ans + "C";
  else if(pos==0 && neg != 0) ans = ans + "~C";

  pos = 0, neg = 0;
  for(string s: vec){
    if(s == "D") pos++;
    if( s == "~D") neg++;
  }
  if(pos!=0 && neg == 0) ans = ans + "D";
  else if(pos==0 && neg != 0) ans = ans + "~D";

  return ans;
}

bool fullRow(int i){
  return grid[i][0] && grid[i][1] && grid[i][2] && grid[i][3];
}
bool fullCol(int i){
  return grid[0][i] && grid[1][i] && grid[2][i] && grid[3][i];
}
bool fullBlock(int i, int j){
  return grid[i][j] && grid[i+1 > 3? 0 : i+1][j] && grid[i][j+1 > 3? 0 : j+1] && grid[i+1 > 3? 0 : i+1][j+1 > 3? 0 : j+1];
}
bool fullTwoRow(int i, int j){
  return grid[i][j] && grid[i][j+1 > 3? 0 : j+1];
}
bool fullTwoCol(int i, int j){
  return grid[i][j] && grid[i+1 > 3? 0 : i+1][j];
}

int main(){
  freopen("/Users/Emerald Liu/Documents/acsl.in","r",stdin);
  freopen("/Users/Emerald Liu/Documents/acsl.out", "w", stdout);
  string s;
  //vector<Point> test;
  //test.push_back((Point){2,0});
  //test.push_back((Point){2,3});
  //printf("%s\n",remove(test).c_str() );
  int cur = 0x00;
  int Case = 0;
  while(scanf("%x",&cur )!=EOF){
    ++Case;
    bool flag=false;
    memset(grid,0,sizeof(grid));
    //printf("%x\n",cur );
    int a = cur / (16*16*16);
    cur %= (16*16*16);
    int b = cur / (16*16);
    cur %= (16*16);
    int c = cur / (16);
    cur %= (16);
    int d = cur;
    //printf("%d %d %d %d\n",a,b,c,d );
      for(int j = 0; j < 4; j++){
        if(1<<(3-j) & a){
          grid[0][j] = 1;
        }
      }
      for(int j = 0; j < 4; j++){
        if(1<<(3-j) & b){
          grid[1][j] = 1;
        }
      }
      for(int j = 0; j < 4; j++){
        if(1<<(3-j) & c){
          grid[2][j] = 1;
        }
      }
      for(int j = 0; j < 4; j++){
        if(1<<(3-j) & d){
          grid[3][j] = 1;
        }
      }
      /*for(int i = 0; i<4;i++){
        printf("\n" );
        for(int j = 0; j<4; j++){
          printf("%d ",grid[i][j] );
        }
      }*/
      //printf("\n" );
      // finished grid initializatoin
      string finalAns = to_string(Case) + ". ";
//# Priority #1
    for(int i = 0; i < 3; i++){
      if(fullRow(i) && fullRow(i+1)){
        vector<Point> ps;
        for(int j = 0; j < 4; j++){
          ps.push_back((Point){i,j});
          ps.push_back((Point){i+1,j});
        }
        if(!flag) flag=true;
        else finalAns += "+";
        finalAns += remove(ps);
      }
    }
    for(int i = 0; i < 3; i++){
      if(fullCol(i) && fullCol(i+1)){
        vector<Point> ps;
        for(int j = 0; j < 4; j++){
          ps.push_back((Point){j,i});
          ps.push_back((Point){j,i+1});
        }
        if(!flag) flag=true;
        else finalAns += "+";
        finalAns += remove(ps);
      }
    }
    //end-row
    if(fullRow(0) && fullRow(3)){
      vector<Point> ps;
      for(int j = 0; j < 4; j++){
        ps.push_back((Point){0,j});
        ps.push_back((Point){3,j});
      }
      if(!flag) flag=true;
      else finalAns += "+";
      finalAns += remove(ps);
    }
    if(fullCol(0) && fullCol(3)){
      vector<Point> ps;
      for(int j = 0; j < 4; j++){
        ps.push_back((Point){j,0});
        ps.push_back((Point){j,3});
      }
      if(!flag) flag=true;
      else finalAns += "+";
      finalAns += remove(ps);
    }
// # priority #2
    for(int i = 0; i < 4; i++){
      if(fullRow(i)){
        vector<Point> ps;
        for(int j = 0; j < 4; j++){
          ps.push_back((Point){i,j});
        }
        if(!flag) flag=true;
        else finalAns += "+";
        finalAns += remove(ps);
      }
    }
    for(int i = 0; i < 4; i++){
      if(fullCol(i)){
        vector<Point> ps;
        for(int j = 0; j < 4; j++){
          ps.push_back((Point){j,i});
        }
        if(!flag) flag=true;
        else finalAns += "+";
        finalAns += remove(ps);
      }
    }
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        if(fullBlock(i,j)){
          vector<Point> ps;
          ps.push_back((Point){i,j}),ps.push_back((Point){i,j+1}),ps.push_back((Point){i+1,j}),ps.push_back((Point){i+1,j+1});
          if(!flag) flag=true;
          else finalAns += "+";
          finalAns += remove(ps);
        }
      }
    }
    // end-row 4 adjcent X's
    for(int j = 0; j < 3; j++){
      if(fullBlock(3,j)){
        vector<Point> ps;
        ps.push_back((Point){3,j}),ps.push_back((Point){3,j+1}),ps.push_back((Point){0,j}),ps.push_back((Point){0,j+1});
        if(!flag) flag=true;
        else finalAns += "+";
        finalAns += remove(ps);
      }
    }
    // end-col 4 adjcent X's
    for(int i = 0; i < 3; i++){
      if(fullBlock(i,3)){
        vector<Point> ps;
        ps.push_back((Point){i,3}),ps.push_back((Point){i+1,3}),ps.push_back((Point){i,0}),ps.push_back((Point){i+1,0});
        if(!flag) flag=true;
        else finalAns += "+";
        finalAns += remove(ps);
      }
    }
//# priority #4
    if(grid[0][0] && grid[0][3] && grid[3][0] && grid[3][3]){
      vector<Point> ps;
      ps.push_back((Point){0,0}), ps.push_back((Point){0,3}), ps.push_back((Point){3,0}), ps.push_back((Point){3,3});
      if(!flag) flag=true;
      else finalAns += "+";
      finalAns += remove(ps);
    }
//# priority #5
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 3; j++){
      if(fullTwoRow(i, j)){
        vector<Point> ps;
        ps.push_back((Point){i,j}), ps.push_back((Point){i,j+1});
        if(!flag) flag=true;
        else finalAns += "+";
        finalAns += remove(ps);
      }
    }
  }
  for(int j = 0; j < 4; j++){
    for(int i = 0; i < 3; i++){
      if(fullTwoCol(i, j)){
        vector<Point> ps;
        ps.push_back((Point){i,j}), ps.push_back((Point){i+1,j});
        if(!flag) flag=true;
        else finalAns += "+";
        finalAns += remove(ps);
      }
    }
  }
//# priority #6
  for(int i = 0; i < 4; i++){
    if(fullTwoRow(i, 3)){
      vector<Point> ps;
      ps.push_back((Point){i,0}), ps.push_back((Point){i,3});
      if(!flag) flag=true;
      else finalAns += "+";
      finalAns += remove(ps);
    }
  }
  for(int j = 0; j < 4; j++){
    if(fullTwoCol(3, j)){
      vector<Point> ps;
      ps.push_back((Point){0,j}), ps.push_back((Point){3,j});
      if(!flag) flag=true;
      else finalAns += "+";
      finalAns += remove(ps);
    }
  }
  
//# priority #7
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      if(grid[i][j]){
        vector<Point> ps;
        ps.push_back((Point){i,j});
        if(!flag) flag=true;
        else finalAns += "+";
        finalAns += remove(ps);
      }
    }
  }
  printf("%s\n",&finalAns[0] );
  }
}
