template<typename T> struct Fenweick{
    vector<T> da;
    int size;
    Fenweick(int sz):size(sz){da.resize(size);}

    template <typename TEMP>
    Fenweick(vector<TEMP> const &a) : Fenweick(a.size()) {
    for(size_t i = 0; i < a.size(); i++)
        add(i, a[i]);
    }

    void add(int p, T v){
        for(;p<size;da[p] += v, p |= p+1);
    }

    T sum(int p){
        T re=0;for(;p>=0;re += da[p], p = (p&(p+1)) - 1);return re;
    }

    T range(int l, int r){
        return sum(r) - sum(l-1);
    }
};