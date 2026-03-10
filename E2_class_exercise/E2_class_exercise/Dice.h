#ifndef E2_CLASS_EXERCISE_DICE_H
#define E2_CLASS_EXERCISE_DICE_H
#include <cstdlib>
#include <ctime>


class Dice {
public:
    explicit Dice(int n): faces(n) {
        if (n<=2)
            faces = 6;
        srand(time(0));
    }

    int roll(int r);

private:
    int faces;
    static int rollsNum;
    const int MAX_ROLLS = 10000;
};


#endif //E2_CLASS_EXERCISE_DICE_H
