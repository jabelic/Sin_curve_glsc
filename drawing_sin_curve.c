
#include <glsc.h>
#include <stdio.h>
#include <math.h>

// 定数の定義
#define N (100)
#define K (100)
#define PI (3.1415926535)
#define L (2 * PI)
//時間t=[0,T]
#define T (10.0)

//点が縦に移動していき,sin,cosカーブのアニメーションを描写.

int main(){
  int i;
  double k;
  double Y[N], dx;
  double dt;
  char text[256];

  //dx,dtを計算
  dx = L/(N - 1);
  dt = T/(K - 1);
  //初期設定
  g_init("GRAPH", 200.0, 200.0);
  g_device(G_DISP);

  //仮想座標系の定義
  g_def_scale(1, 0.0, L, -1.0, 1.0, 10.0, 10.0, 180.0, 80.0);
  g_def_scale(2, 0.0, L, -1.0, 1.0, 10.0, 110.0, 180.0, 80.0);
  //
  for(k = 0; k < K; k++){
    //上の図
    g_sel_scale(1);

    //グラフの名前
    sprintf(text, "moving sin curve(N=100)");
    //表示
    g_text(85,7,text);

    //軸ラベル
    g_text(3,13,"1.0");
    g_text(3,53,"0.0");
    g_text(1,90,"-1.0");
    g_text(8,95,"0.0");
    g_text(98,95,"PI");
    g_text(188,95,"2PI");
    //外枠の描画（グラフの消去）
    g_area_color(G_WHITE);
    g_line_color(G_BLACK);
    g_line_width(2);
    g_box(0.0, L, -1.0, 1.0, G_YES, G_YES);

    //x軸
    g_move(0.0, 0.0);
    g_plot(L, 0.0);

    //y軸
    g_move(L/2.0, 1.0);
    g_plot(L/2.0, -1.0);

    //Y[i]
    for(i = 0; i < N; i++){
      Y[i] = sin(i*dx + k*dt);
    }

    //折れ線を描く (g_data_plot)
    g_line_color(G_RED);
    g_line_type(G_LINE_SOLID);
    g_line_width(2);

    //カレント座標系における左端から右端まで範囲を指定し配列YをN個表示するので配列Xは不要
    g_data_plot(0.0, L, Y, N);






    g_sel_scale(2);
    //外枠の描画（グラフの消去）
    //紫紺
    g_area_color(g_rgb_color(0.2,0.05,0.4));
    g_line_color(G_BLACK);
    g_line_width(2);
    g_box(0.0, L, -1.0, 1.0, G_YES, G_YES);

    //グラフの名前
    sprintf(text, "moving cos curve(N=100)");
    //表示
    g_text(85,107,text);

    //軸ラベル
    g_text(3,113,"1.0");
    g_text(3,153,"0.0");
    g_text(1,190,"-1.0");
    g_text(8,195,"0.0");
    g_text(98,195,"PI");
    g_text(188,195,"2PI");


    //x軸の描画
    g_move(0.0, 0.0);
    g_plot(L, 0.0);

    //y軸の描画
    g_move(L/2.0, 1.0);
    g_plot(L/2.0, -1.0);

    //Y[i] を計算(引数k)
    for(i = 0; i < N; i++){
      Y[i] = cos(i*dx + k*dt);
    }

    //折れ線を描く (g_data_plot)
    g_line_color(G_WHITE);
    g_line_type(G_LINE_SOLID);
    g_line_width(3);

    //カレント座標系における左端から右端まで範囲を指定し配列YをN個表示するので配列Xは不要
    g_data_plot(0.0, L, Y, N);

    g_sleep(0.05);
  }





  g_sleep(G_STOP);
  g_term();

  return 0;
}
