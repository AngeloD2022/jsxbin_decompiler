//
// Created by Angelo DeLuca on 12/1/21.
//

#ifndef JSXBIN_DECOMPILER_ARGUMENTLIST_H
#define JSXBIN_DECOMPILER_ARGUMENTLIST_H

#pragma once

#include "AbstractNode.h"
#include "../decoders.h"
#include <vector>

using namespace jsxbin;

namespace jsxbin::nodes {

    class ArgumentList : public AbstractNode {
    public:
        explicit ArgumentList(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

        vector<AbstractNode*> arguments;

    private:
        bool unkValue;

    };
}

#endif //JSXBIN_DECOMPILER_ARGUMENTLIST_H
