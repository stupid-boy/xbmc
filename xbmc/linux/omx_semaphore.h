/**
  @file src/omx_semaphore.h

  Implements a simple inter-thread semaphore so not to have to deal with IPC
  creation and the like.

  Copyright (C) 2007-2008 STMicroelectronics
  Copyright (C) 2007-2008 Nokia Corporation and/or its subsidiary(-ies).

  This library is free software; you can redistribute it and/or modify it under
  the terms of the GNU Lesser General Public License as published by the Free
  Software Foundation; either version 2.1 of the License, or (at your option)
  any later version.

  This library is distributed in the hope that it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
  FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
  details.

  You should have received a copy of the GNU Lesser General Public License
  along with this library; if not, write to the Free Software Foundation, Inc.,
  51 Franklin St, Fifth Floor, Boston, MA
  02110-1301  USA

  $Date: 2008-06-27 12:00:23 +0200 (Fri, 27 Jun 2008) $
  Revision $Rev: 554 $
  Author $Author: pankaj_sen $

*/

#pragma once

#ifndef __OMX_SEMAPHORE_H__
#define __OMX_SEMAPHORE_H__

#include <semaphore.h>

/** The structure contains the semaphore value, mutex and green light flag
 */ 
typedef struct omx_tsem_t {
  pthread_cond_t condition;
  pthread_mutex_t mutex;
  unsigned int semval;
} omx_tsem_t;

/** Initializes the semaphore at a given value
 * 
 * @param tsem the semaphore to initialize
 * 
 * @param val the initial value of the semaphore
 */
void omx_tsem_init(omx_tsem_t* tsem, unsigned int val);

/** Destroy the semaphore
 *  
 * @param tsem the semaphore to destroy
 */
void omx_tsem_deinit(omx_tsem_t* tsem);

/** Decreases the value of the semaphore. Blocks if the semaphore
 * value is zero.
 * 
 * @param tsem the semaphore to decrease
 */
void omx_tsem_down(omx_tsem_t* tsem);

/** Increases the value of the semaphore
 * 
 * @param tsem the semaphore to increase
 */
void omx_tsem_up(omx_tsem_t* tsem);

/** Reset the value of the semaphore
 * 
 * @param tsem the semaphore to reset
 */
void omx_tsem_reset(omx_tsem_t* tsem);

/** Wait on the condition.
 * 
 * @param tsem the semaphore to wait
 */
void omx_tsem_wait(omx_tsem_t* tsem);

/** Signal the condition,if waiting
 * 
 * @param tsem the semaphore to signal
 */
void omx_tsem_signal(omx_tsem_t* tsem);

#endif
