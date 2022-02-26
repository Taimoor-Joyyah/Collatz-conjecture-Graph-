#include <stdio.h>
#include <stdlib.h>

struct coordinate{
    long long x;
    long long y;
};
struct graph{
    struct coordinate min;
    struct coordinate max;
    struct coordinate data[1024];
    struct coordinate frame;
};
void graphing(int);

int main() {
    //int Number;
    for(int i = 2; 1; i++) {
        printf("Current Number : %d", i);
        //scanf("%d", &Number);
        graphing(i);
        getch();
        system("cls");
    }
}
void graphing(int Number)
{
    struct graph Graph;

    int i, j;
    long long Num = (long long)Number, max = 0;
    int Ilt;

    for(i = 0; Num != 1; i++) {
        if(max < Num) max = Num;
        Graph.data[i].x = i;
        Graph.data[i].y = Num;
        if(Num % 2 != 0)
            Num = 3 * Num + 1;
        else
            Num /= 2;
    }
    Ilt = i;
    Graph.data[Ilt].x = Ilt;
    Graph.data[Ilt].y = Num;

    printf("\n\tIlteration : %d", Ilt);
    printf("\n\tMaximum    : %lld\n\n", max);

    //initialize graph data
    Graph.min.x = 0;
    Graph.max.x = Ilt;
    Graph.min.y = 0;
    //Graph.max.y = max;
    Graph.frame.x = Ilt+1;
    Graph.frame.y = Graph.frame.x;

    //initializing frame
    int framesize = Graph.frame.y*(Graph.frame.x+1);
    unsigned char frame[framesize];
    for(i = 0; i < framesize; i++) {
        frame[i] = 176;
    }
    for(i = 0; i < Graph.frame.y; i++)
        frame[i*(Graph.frame.x+1)-1] = '\n';
    frame[Graph.frame.y*(Graph.frame.x+1)-1] = 0;
    //graph data to frame
    double a;
    /*for(i = 0; i <= Graph.max.x; i++) {
        a = (double)Graph.max.x-((double)Graph.data[i].y*(double)Graph.max.x)/(double)Graph.max.y;
        for(j = Graph.max.x; j >= (int)a; j--) {
            frame[j][i] = 178;
        }
    }*/
    for(i = 0; i < Graph.frame.x; i++) {
        a = (double)Graph.frame.y-1-((double)Graph.data[i].y*(double)Graph.frame.y)/(double)max;
        for(j = Graph.frame.y-1; j >= (long long)a; j--) {
            frame[j*(Graph.frame.x+1)+i] = 178;
        }
    }
    //printing frame
    /*for(i = 0; i < Graph.frame.y; i++) {
        for(j = 0; j < Graph.frame.x; j++) {
            printf("%c", frame[i][j]);
        }
        printf("\n");
    }*/
    puts(frame);
}
