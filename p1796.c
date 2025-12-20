#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 105
#define MAX_K 105
#define MAX_EDGES 105
#define INF 0x3f3f3f3f
typedef struct {
    int from_planet;
    int cost;
} Edge;
typedef struct {
    int edge_count;//从该星球出发的航线数量
    Edge edges[MAX_EDGES];//航线数组
}Planet;
typedef struct{
    int planet_count;//该等级星球数量
    Planet planets[MAX_K];//星球数组
}Level;

typedef struct{
    int cost;
    int prev_planet;
}DPState;//DP状态结构体
typedef struct{
    DPState dp[MAX_N][MAX_K];//等级 星球编号
    int min_final_cost;
    int best_planet;
}Solution;
void init_structures(Level levels[],Solution*sol,int n)
{
    for (int i=0;i<=n;i++)
    {
        levels[i].planet_count=0;
        for (int j=1;j<MAX_K;j++)
        {
            levels[i].planets[j].edge_count=0;
        }
    }
    sol->min_final_cost=INF;
    sol->best_planet=-1;
    for (int i=0;i<=n;i++)
    {
        for (int j=1;j<MAX_K;j++)
        {
            sol->dp[i][j].cost=INF;
            sol->dp[i][j].prev_planet=-1;
        }
    }

}
void read_and_build(Level levels[],int n)//传递n的地址以读取n
{
    levels[0].planet_count=1;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&levels[i].planet_count);//该等级的星球数
        for (int j=1;j<=levels[i].planet_count;j++)
        {
            Planet *planet=&levels[i].planets[j];
            planet->edge_count=0;
            int from_planet;
            while(1){
                scanf("%d",&from_planet);
                if (from_planet==0) break;
                int cost;
                scanf("%d",&cost);
                planet->edges[planet->edge_count].from_planet=from_planet;
                planet->edges[planet->edge_count].cost=cost;
                planet->edge_count++;
            }
        }
    }
}
void solve_dp(Level levels[],Solution*sol,int n){
    sol->dp[0][1].cost=0;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=levels[i].planet_count;j++)
        {
            Planet*planet=&levels[i].planets[j];
            for (int e=0;e<planet->edge_count;e++)
            {
                Edge*edge=&planet->edges[e];
                int from_level=i-1;
                int from_planet=edge->from_planet;
                int new_cost=sol->dp[from_level][from_planet].cost+edge->cost;
                if (new_cost<sol->dp[i][j].cost)
                {
                    sol->dp[i][j].cost=new_cost;
                    sol->dp[i][j].prev_planet=from_planet;
                    
                }
            }
        }
    }
    for (int i=1;i<=levels[n].planet_count;i++)
    {
        if (sol->dp[n][i].cost<sol->min_final_cost)
        sol->min_final_cost=sol->dp[n][i].cost;
    }
    
}
int main(){
    Level levels[MAX_N];
    Solution solution;
    int n=0;
    scanf("%d",&n);
    init_structures(levels,&solution,n);
    read_and_build(levels,n);
    solve_dp(levels,&solution,n);
    printf("%d\n",solution.min_final_cost);
    return 0;
}