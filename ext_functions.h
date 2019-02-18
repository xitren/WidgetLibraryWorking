/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef EXT_FUNCTIONS_H
#define EXT_FUNCTIONS_H

#ifdef __cplusplus
extern "C" {
#endif

void ef_max(
        void *buf,
        uint32_t nbuf,
        void *max,
        void *index);

void ef_min(
        void *buf,
        uint32_t nbuf,
        void *min,
        void *index);

#ifdef __cplusplus
}
#endif

#endif /* EXT_FUNCTIONS_H */

