struct Seg{
    int maxl=0, minl=0, maxr=0, minr=0, mx=0, mi=0, seg=0;
    Seg(){
        maxl=0, minl=0, maxr=0, minr=0, mx=0, mi=0, seg=0;
    }
    Seg(int a, int b, int c, int d, int f, int g, int h){
        maxl=a, minl=b, maxr=c, minr=d, mx=f, mi=g, seg=h;
    }

    Seg& operator+=(const Seg& rhs){
        mx = max(mx, max(rhs.mx, maxr+rhs.maxl));
        mi = min(mi, min(rhs.mi, minr+rhs.minl));
        maxl = max(maxl, seg + rhs.maxl);
        minl = min(minl, seg + rhs.minl);
        maxr = max(rhs.maxr, rhs.seg + maxr);
        minr = min(rhs.minr, rhs.seg + minr);
        seg+=rhs.seg;
        return *this;
    }

    friend Seg operator+(Seg lhs, const Seg& rhs) 
    {
        lhs += rhs; 
        return lhs; 
    }
};

std::ostream& operator<<(std::ostream& os, const Seg& obj)
{
    os << obj.maxl<<" "<< obj.minl<<" "<< obj.maxr<<" "<< obj.minr<<" "<< obj.mx<<" "<< obj.mi<<" "<< obj.seg;
    return os;
}

const int NLCA = 100005;
int fa[NLCA][20], tin[NLCA], tout[NLCA];
int ti;
function<bool(int, int)> isans = [&](int x, int y){
    return tin[x] <= tin[y] and tout[y] <= tout[x];
};

function<int(int, int)> lca = [&](int x, int y){
    if(isans(x, y))return x;
    if(isans(y, x))return y;
    for(int i=19;i>=0;i--)if(not isans(fa[x][i], y))x = fa[x][i];
    return fa[x][0];
};

function<void(int, int, int)> dfs = [&](int p, int pa, int h){
    tin[p] = ti++;
    fa[p][0] = pa;
    dph[p] = h;
    for(int j=1;j<20;j++)fa[p][j] = fa[fa[p][j-1]][j-1];
    for(auto adj:G[p])if(adj != pa)dfs(adj, p, h+1);
    tout[p] = ti++;
};

dfs(1, 1, 0);