/******************************************************************************
 * Copyright 2015 ASDF developers
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
/**
 * @file ASDF_provenance.h
 * @brief
 * @author Matthieu Lefebvre
 */

#ifndef _ASDF_PROVENANCE_H_
#define _ASDF_PROVENANCE_H_

/**
 * @brief Generate a provenance entity with id prov_id and label prov_label
 *        from a specfem style parameter file ("Par_file") into a C string prov.
 *
 * @param filename Name of the "Par_file".
 * @param prov_label Description, for instance "SPECFEM Input Parameters".
 * @param prov_id Unique id for this provenance item.
 * @param prov Output, pointer to the generated C string.
 */
void ASDF_generate_par_file_provenance(const char *filename,
                                       const char *prov_label,
                                       const char *prov_id,
                                       char **prov);

/**
 * @brief Deallocate the sub_provenance string build by
 *        ASDF_generate_par_file_provenance and other provenance subroutines
 *
 * @param sub_provenance Pointer to the C string to deallocate.
 */
void ASDF_clean_par_file_provenance(char *sub_provenance);

/**
 * @brief Generate full provenance for a specfem style solver.
 *
 * @param filename Name of the "Prov_file" to parse
 * @param startTime start time of the simulation
 * @param endTime end time of the simulation
 * @param prov Output, pointer to the generated C string.
 * @param len Length of prov string
 */
void ASDF_generate_sf_provenance(const char *startTime,
                                 const char *endTime,
                                 char **prov,
                                 int *len);

/**
 * @brief Free the memeory associated with the provenance string
 *
 * @param provenance Pointer to the string that is freed in memory
 *
 */

void ASDF_clean_provenance(char **provenance);

#endif  /* _ASDF_PROVENANCE_H_ */
