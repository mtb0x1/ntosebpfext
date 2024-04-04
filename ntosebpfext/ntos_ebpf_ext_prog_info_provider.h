// Copyright (c) Microsoft Corporation
// SPDX-License-Identifier: MIT

#pragma once

#include "ntos_ebpf_ext.h"

typedef struct _ntos_ebpf_extension_program_info_provider ntos_ebpf_extension_program_info_provider_t;

/**
 * @brief Data structure for program info NPI provider registration parameters.
 */
typedef struct _ntos_ebpf_extension_program_info_provider_parameters
{
    const NPI_MODULEID* provider_module_id;     ///< NPI provider module ID.
    const ebpf_extension_data_t* provider_data; ///< Program info NPI provider data (contains ebpf_program_data_t).
} ntos_ebpf_extension_program_info_provider_parameters_t;

/**
 * @brief Register the program information NPI provider.
 *
 * @param[in] provider_characteristics Pointer to the NPI provider characteristics struct.
 * @param[in, out] provider_context Pointer to the provider context being registered.
 *
 * @retval STATUS_SUCCESS Operation succeeded.
 * @retval STATUS_NO_MEMORY Not enough memory to allocate resources.
 */
NTSTATUS
ntos_ebpf_extension_program_info_provider_register(
    _In_ const ntos_ebpf_extension_program_info_provider_parameters_t* parameters,
    _Outptr_ ntos_ebpf_extension_program_info_provider_t** provider_context);

/**
 * @brief Unregister the program information NPI provider.
 *
 * @param[in] provider_context Pointer to the provider context being un-registered.
 */
void
ntos_ebpf_extension_program_info_provider_unregister(
    _In_opt_ _Frees_ptr_opt_ ntos_ebpf_extension_program_info_provider_t* provider_context);