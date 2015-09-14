#pragma once

#include "types.h"

namespace au {
namespace fmt {
namespace entis {
namespace common {

    static const int prob_escape_code = -1;
    static const size_t prob_symbol_sorts = 0x101;
    static const size_t prob_total_limit = 0x2000;

    struct CodeSymbol
    {
        u16 occurrences;
        i16 symbol;
    };

    struct ProbModel
    {
        ProbModel();
        void half_occurrence_count();
        void increase_symbol(int index);
        i16 find_symbol(i16 symbol);

        u32 total_count;
        u32 symbol_sorts;
        CodeSymbol sym_table[prob_symbol_sorts];
    };

} } } }
