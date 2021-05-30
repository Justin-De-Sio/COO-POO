#ifndef DUREE_H
#define DUREE_H

namespace nsUtil {
    typedef unsigned short US ;
    typedef unsigned long long ULL ;

    class Duree{

    public:
    Duree(const ULL duree = ULL (0) );
    ~Duree();
    void display(void) const;
    ULL getDuree(void) const;
    void incr(const ULL delta = ULL (0));
    void decr(const ULL delta = ULL (0));
    private:
        void normaliser(void);

        ULL myDuree;
        US mySeconds;
        US myMinutes;
        US myHours;
        ULL myDays;

    };
}



#endif // DUREE_H
