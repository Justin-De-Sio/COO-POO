#ifndef DUREE_H
#define DUREE_H

namespace nsUtil {
    typedef unsigned short US ;
    typedef unsigned long UL ;

    class Duree{

    public:
    Duree(const UL duree);
    void display(void) const;
    UL getDuree(void) const;
    void incr(const UL delta = UL (0));
    void decr(const UL delta = UL (0));
    private:
        void normaliser(void);

        UL myDuree;
        US mySeconds;
        US myMinutes;
        US myHours;
        UL myDays;

    };
}



#endif // DUREE_H
