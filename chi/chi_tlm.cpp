/*
 * Copyright 2020 Arteris IP
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "chi_tlm.h"
#include <iostream>

namespace chi
{
    std::array<char const *, 103> opc2str = {
        "ReqLCrdReturn",
        "ReadShared",
        "ReadClean",
        "ReadOnce",
        "ReadNoSnp",
        "PCrdReturn",
        "Reserved",
        "ReadUnique",
        "CleanShared",
        "CleanInvalid",
        "MakeInvalid",
        "CleanUnique",
        "MakeUnique",
        "Evict",
        "EOBarrier",
        "ECBarrier",
        "RESERVED",
        "ReadNoSnpSep",
        "RESERVED",
        "CleanSharedPersistSep",
        "DVMOp",
        "WriteEvictFull",
        "WriteCleanPtl",
        "WriteCleanFull",
        "WriteUniquePtl",
        "WriteUniqueFull",
        "WriteBackPtl",
        "WriteBackFull",
        "WriteNoSnpPtl",
        "WriteNoSnpFull",
        "RESERVED",
        "RESERVED",
        "WriteUniqueFullStash",
        "WriteUniquePtlStash",
        "StashOnceShared",
        "StashOnceUnique",
        "ReadOnceCleanInvalid",
        "ReadOnceMakeInvalid",
        "ReadNotSharedDirty",
        "CleanSharedPersist",
        "AtomicStoreAdd",
        "AtomicStoreClr",
        "AtomicStoreEor",
        "AtomicStoreSet",
        "AtomicStoreSmax",
        "AtomicStoreSmin",
        "AtomicStoreUmax",
        "AtomicStoreUmin",
        "AtomicLoadAdd",
        "AtomicLoadClr",
        "AtomicLoadEor",
        "AtomicLoadSet",
        "AtomicLoadSmax",
        "AtomicLoadSmin",
        "AtomicLoadUmax",
        "AtomicLoadUmin",
        "AtomicSwap",
        "AtomicCompare",
        "PrefetchTgt",
        "RESERVED",
        "RESERVED",
        "RESERVED",
        "RESERVED",
        "RESERVED",
        "RESERVED",
        "MakeReadUnique",
        "WriteEvictOrEvict",
        "WriteUniqueZero",
        "WriteNoSnpZero",
        "RESERVED",
        "RESERVED",
        "StashOnceSepShared",
        "StashOnceSepUnique",
        "RESERVED",
        "RESERVED",
        "RESERVED",
        "ReadPreferUnique",
        "RESERVED",
        "RESERVED",
        "RESERVED",
        "WriteNoSnpFullCleanSh",
        "WriteNoSnpFullCleanInv",
        "WriteNoSnpFullCleanShPerSep",
        "RESERVED",
        "WriteUniqueFullCleanSh",
        "RESERVED",
        "WriteUniqueFullCleanShPerSep",
        "RESERVED",
        "WriteBackFullCleanSh",
        "WriteBackFullCleanInv",
        "WriteBackFullCleanShPerSep",
        "RESERVED",
        "WriteCleanFullCleanSh",
        "RESERVED",
        "WriteCleanFullCleanShPerSep",
        "RESERVED",
        "WriteNoSnpPtlCleanSh",
        "WriteNoSnpPtlCleanInv",
        "WriteNoSnpPtlCleanShPerSep",
        "RESERVED",
        "WriteUniquePtlCleanSh",
        "RESERVED",
        "WriteUniquePtlCleanShPerSep",
    };
    template <>
    const char *to_char<req_optype_e>(req_optype_e v)
    {
        auto idx = static_cast<unsigned>(v);
        if (idx < opc2str.size())
            return opc2str[idx];
        else
            return "RESERVED";
    }

    template <>
    const char *to_char<dat_optype_e>(dat_optype_e v)
    {
        switch (v)
        {
        case dat_optype_e::DataLCrdReturn:
            return "DataLCrdReturn";
        case dat_optype_e::SnpRespData:
            return "SnpRespData";
        case dat_optype_e::CopyBackWrData:
            return "CopyBackWrData";
        case dat_optype_e::NonCopyBackWrData:
            return "NonCopyBackWrData";
        case dat_optype_e::CompData:
            return "CompData";
        case dat_optype_e::SnpRespDataPtl:
            return "SnpRespDataPtl";
        case dat_optype_e::SnpRespDataFwded:
            return "SnpRespDataFwded";
        case dat_optype_e::WriteDataCancel:
            return "WriteDataCancel";
        case dat_optype_e::DataSepResp:
            return "DataSepResp";
        case dat_optype_e::NCBWrDataCompAck:
            return "NCBWrDataCompAck";
        default:
            return "UNKNOWN_dat_optype_e";
        }
    }

    template <>
    const char *to_char<rsp_optype_e>(rsp_optype_e v)
    {
        switch (v)
        {
        case rsp_optype_e::RespLCrdReturn:
            return "RespLCrdReturn";
        case rsp_optype_e::SnpResp:
            return "SnpResp";
        case rsp_optype_e::CompAck:
            return "CompAck";
        case rsp_optype_e::RetryAck:
            return "RetryAck";
        case rsp_optype_e::Comp:
            return "Comp";
        case rsp_optype_e::CompDBIDResp:
            return "CompDBIDResp";
        case rsp_optype_e::DBIDResp:
            return "DBIDResp";
        case rsp_optype_e::PCrdGrant:
            return "PCrdGrant";
        case rsp_optype_e::ReadReceipt:
            return "ReadReceipt";
        case rsp_optype_e::SnpRespFwded:
            return "SnpRespFwded";
        case rsp_optype_e::TagMatch:
            return "TagMatch";
        case rsp_optype_e::RespSepData:
            return "RespSepData";
        case rsp_optype_e::Persist:
            return "Persist";
        case rsp_optype_e::CompPersist:
            return "CompPersist";
        case rsp_optype_e::DBIDRespOrd:
            return "DBIDRespOrd";
        case rsp_optype_e::StashDone:
            return "StashDone";
        case rsp_optype_e::CompStashDone:
            return "CompStashDone";
        case rsp_optype_e::CompCMO:
            return "CompCMO";
        case rsp_optype_e::INVALID:
            return "---";
        default:
            return "UNKNOWN_rsp_optype_e";
        }
    }

    template <>
    const char *to_char<snp_optype_e>(snp_optype_e v)
    {
        switch (v)
        {
        case snp_optype_e::SnpLCrdReturn:
            return "SnpLCrdReturn";
        case snp_optype_e::SnpShared:
            return "SnpShared";
        case snp_optype_e::SnpClean:
            return "SnpClean";
        case snp_optype_e::SnpOnce:
            return "SnpOnce";
        case snp_optype_e::SnpNotSharedDirty:
            return "SnpNotSharedDirty";
        case snp_optype_e::SnpUniqueStash:
            return "SnpUniqueStash";
        case snp_optype_e::SnpMakeInvalidStash:
            return "SnpMakeInvalidStash";
        case snp_optype_e::SnpUnique:
            return "SnpUnique";
        case snp_optype_e::SnpCleanShared:
            return "SnpCleanShared";
        case snp_optype_e::SnpCleanInvalid:
            return "SnpCleanInvalid";
        case snp_optype_e::SnpMakeInvalid:
            return "SnpMakeInvalid";
        case snp_optype_e::SnpStashUnique:
            return "SnpStashUnique";
        case snp_optype_e::SnpStashShared:
            return "SnpStashShared";
        case snp_optype_e::SnpDVMOp:
            return "SnpDVMOp";
        case snp_optype_e::SnpSharedFwd:
            return "SnpSharedFwd";
        case snp_optype_e::SnpCleanFwd:
            return "SnpCleanFwd";
        case snp_optype_e::SnpOnceFwd:
            return "SnpOnceFwd";
        case snp_optype_e::SnpNotSharedDirtyFwd:
            return "SnpNotSharedDirtyFwd";
        case snp_optype_e::SnpUniqueFwd:
            return "SnpUniqueFwd";
        default:
            return "UNKNOWN_snp_optype_e";
        }
    }

    template <>
    const char *to_char<dat_resptype_e>(dat_resptype_e v)
    {
        switch (v)
        {
        // case CompData_I: return "CompData_I";
        // case DataSepResp_I: return "DataSepResp_I";
        // case RespSepData_I: return "RespSepData_I";
        // case CompData_UC: return "CompData_UC";
        // case DataSepResp_UC: return "DataSepResp_UC";
        // case RespSepData_UC: return "RespSepData_UC";
        // case CompData_SC: return "CompData_SC";
        // case DataSepResp_SC: return "DataSepResp_SC";
        // case RespSepData_SC: return "RespSepData_SC";
        case dat_resptype_e::CompData_UD_PD:
            return "CompData_UD_PD";
        case dat_resptype_e::CompData_SD_PD:
            return "CompData_SD_PD";
        case dat_resptype_e::Comp_I:
            return "Comp_I";
        case dat_resptype_e::Comp_UC:
            return "Comp_UC";
        case dat_resptype_e::Comp_SC:
            return "Comp_SC";
        // case CopyBackWrData_I: return "CopyBackWrData_I";
        // case CopyBackWrData_UC: return "CopyBackWrData_UC";
        // case CopyBackWrData_SC: return "CopyBackWrData_SC";
        // case CopyBackWrData_UD_PD: return "CopyBackWrData_UD_PD";
        // case CopyBackWrData_SD_PD: return "CopyBackWrData_SD_PD";
        // case NonCopyBackWrData: return "NonCopyBackWrData";
        // case NCBWrDataCompAck: return "NCBWrDataCompAck";
        default:
            return "UNKNOWN_dat_resptype_e";
        }
    }

    template <>
    const char *to_char<rsp_resptype_e>(rsp_resptype_e v)
    {
        switch (v)
        {
        case rsp_resptype_e::SnpResp_I:
            return "SnpResp_I";
        case rsp_resptype_e::SnpResp_SC:
            return "SnpResp_SC";
        case rsp_resptype_e::SnpResp_UC:
            return "SnpResp_UC";
        // case SnpResp_UD: return "SnpResp_UD";
        case rsp_resptype_e::SnpResp_SD:
            return "SnpResp_SD";
        default:
            return "UNKNOWN_rsp_resptype_e";
        }
    }

    template <>
    const char *to_char<credit_type_e>(credit_type_e v)
    {
        switch (v)
        {
        case credit_type_e::LINK:
            return "LINK";
        case credit_type_e::REQ:
            return "REQ";
        case credit_type_e::RESP:
            return "RESP";
        case credit_type_e::DATA:
            return "DATA";
        default:
            return "credit_type_e";
        }
    }

    template <>
    bool is_valid<chi::chi_ctrl_extension>(chi_ctrl_extension *ext)
    {
        auto sz = ext->req.get_size();
        if (sz > 6)
            return false;
        return true;
    }

} // namespace chi
