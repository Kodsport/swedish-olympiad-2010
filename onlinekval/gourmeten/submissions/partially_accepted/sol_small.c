#include <stdio.h>
#include <assert.h>

#define ll long long int

ll nw[1000];
int t[30],N,M;

ll numways(int r) {  //r är hur lång tid som återstår
  int p;
  ll sum;
  if(r < 0) return 0;            //Ingen lösning
  if(r == 0) return 1;          //Det gick jämnt upp. En lösning hittad.
  if(nw[r]!=-1) return nw[r];           //Den magiska raden
  sum=0;
  for(p=0;p<N;p++) sum+=numways(r-t[p]);     //Testa varje maträtt och rekursera!
  nw[r]=sum;
  assert(sum <= 2000000);
  return sum;
}

int main() {
  int i;
  scanf("%d %d", &M, &N);
  for(i=0;i<N;i++) scanf("%d", &t[i]);
  for(i=0;i<=M;i++) nw[i]=-1;               //Låt -1 betyda att vi inte räknat ut värdet ännu 
  printf("%lld\n", numways(M));
  return 0;
}
