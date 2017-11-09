// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ProtoId.proto

#ifndef PROTOBUF_ProtoId_2eproto__INCLUDED
#define PROTOBUF_ProtoId_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3004000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
// @@protoc_insertion_point(includes)
namespace NetProto {
}  // namespace NetProto

namespace NetProto {

namespace protobuf_ProtoId_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static void InitDefaultsImpl();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_ProtoId_2eproto

enum ProtoId {
  PID_Min = 0,
  PID_Ping = 1,
  PID_Pong = 2,
  PID_QueryFreeHero = 100,
  PID_RspFreeHero = 101,
  PID_SelectHeroReq = 102,
  PID_SelectHeroRsp = 103,
  PID_LoadSceneComplete = 104,
  PID_LeaveScene = 105,
  PID_PullAllSceneInfo = 106,
  PID_PullAllSceneInfoRsp = 107,
  PID_SceneObjectState = 1000,
  PID_MoveObjectState = 1010,
  PID_MoveObjectMutableState = 1011,
  PID_MoveToPos = 1020,
  PID_StopMove = 1030,
  PID_BattleOperaReq = 1100,
  PID_Max = 5120,
  ProtoId_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  ProtoId_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool ProtoId_IsValid(int value);
const ProtoId ProtoId_MIN = PID_Min;
const ProtoId ProtoId_MAX = PID_Max;
const int ProtoId_ARRAYSIZE = ProtoId_MAX + 1;

const ::google::protobuf::EnumDescriptor* ProtoId_descriptor();
inline const ::std::string& ProtoId_Name(ProtoId value) {
  return ::google::protobuf::internal::NameOfEnum(
    ProtoId_descriptor(), value);
}
inline bool ProtoId_Parse(
    const ::std::string& name, ProtoId* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ProtoId>(
    ProtoId_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)


}  // namespace NetProto

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::NetProto::ProtoId> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NetProto::ProtoId>() {
  return ::NetProto::ProtoId_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_ProtoId_2eproto__INCLUDED
