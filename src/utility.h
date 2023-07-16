//
// Created by dzxxy on 2023-07-15.
//

#pragma once

namespace CORE {

class Utility {
public:
    static Utility& getInstance();

    int randomInRange(int start, int end);

private:
    Utility();

};


}
