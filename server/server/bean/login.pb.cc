// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: login.proto

#include "login.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

namespace Login {
class LoginDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Login>
      _instance;
} _Login_default_instance_;
class LoginSuccessDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<LoginSuccess>
      _instance;
} _LoginSuccess_default_instance_;
}  // namespace Login
namespace protobuf_login_2eproto {
static void InitDefaultsLogin() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::Login::_Login_default_instance_;
    new (ptr) ::Login::Login();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::Login::Login::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_Login =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsLogin}, {}};

static void InitDefaultsLoginSuccess() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::Login::_LoginSuccess_default_instance_;
    new (ptr) ::Login::LoginSuccess();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::Login::LoginSuccess::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_LoginSuccess =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsLoginSuccess}, {}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_Login.base);
  ::google::protobuf::internal::InitSCC(&scc_info_LoginSuccess.base);
}

::google::protobuf::Metadata file_level_metadata[2];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Login::Login, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Login::Login, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Login::Login, msgid_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Login::Login, name_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Login::Login, password_),
  1,
  0,
  2,
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Login::LoginSuccess, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Login::LoginSuccess, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Login::LoginSuccess, msgid_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Login::LoginSuccess, name_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Login::LoginSuccess, id_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Login::LoginSuccess, email_),
  2,
  0,
  3,
  1,
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 8, sizeof(::Login::Login)},
  { 11, 20, sizeof(::Login::LoginSuccess)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::Login::_Login_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::Login::_LoginSuccess_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "login.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 2);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\013login.proto\022\005Login\"6\n\005Login\022\r\n\005msgId\030\001"
      " \002(\005\022\014\n\004name\030\002 \002(\014\022\020\n\010password\030\003 \002(\005\"F\n\014"
      "LoginSuccess\022\r\n\005msgId\030\001 \002(\005\022\014\n\004name\030\002 \002("
      "\014\022\n\n\002id\030\003 \002(\005\022\r\n\005email\030\004 \001(\014"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 148);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "login.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_login_2eproto
namespace Login {

// ===================================================================

void Login::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Login::kMsgIdFieldNumber;
const int Login::kNameFieldNumber;
const int Login::kPasswordFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Login::Login()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_login_2eproto::scc_info_Login.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:Login.Login)
}
Login::Login(const Login& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_name()) {
    name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.name_);
  }
  ::memcpy(&msgid_, &from.msgid_,
    static_cast<size_t>(reinterpret_cast<char*>(&password_) -
    reinterpret_cast<char*>(&msgid_)) + sizeof(password_));
  // @@protoc_insertion_point(copy_constructor:Login.Login)
}

void Login::SharedCtor() {
  name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&msgid_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&password_) -
      reinterpret_cast<char*>(&msgid_)) + sizeof(password_));
}

Login::~Login() {
  // @@protoc_insertion_point(destructor:Login.Login)
  SharedDtor();
}

void Login::SharedDtor() {
  name_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void Login::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* Login::descriptor() {
  ::protobuf_login_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_login_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const Login& Login::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_login_2eproto::scc_info_Login.base);
  return *internal_default_instance();
}


void Login::Clear() {
// @@protoc_insertion_point(message_clear_start:Login.Login)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    name_.ClearNonDefaultToEmptyNoArena();
  }
  if (cached_has_bits & 6u) {
    ::memset(&msgid_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&password_) -
        reinterpret_cast<char*>(&msgid_)) + sizeof(password_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool Login::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Login.Login)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 msgId = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {
          set_has_msgid();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &msgid_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required bytes name = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_name()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required int32 password = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(24u /* 24 & 0xFF */)) {
          set_has_password();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &password_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:Login.Login)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Login.Login)
  return false;
#undef DO_
}

void Login::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Login.Login)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required int32 msgId = 1;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->msgid(), output);
  }

  // required bytes name = 2;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      2, this->name(), output);
  }

  // required int32 password = 3;
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->password(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:Login.Login)
}

::google::protobuf::uint8* Login::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:Login.Login)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required int32 msgId = 1;
  if (cached_has_bits & 0x00000002u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->msgid(), target);
  }

  // required bytes name = 2;
  if (cached_has_bits & 0x00000001u) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        2, this->name(), target);
  }

  // required int32 password = 3;
  if (cached_has_bits & 0x00000004u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->password(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Login.Login)
  return target;
}

size_t Login::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:Login.Login)
  size_t total_size = 0;

  if (has_name()) {
    // required bytes name = 2;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->name());
  }

  if (has_msgid()) {
    // required int32 msgId = 1;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->msgid());
  }

  if (has_password()) {
    // required int32 password = 3;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->password());
  }

  return total_size;
}
size_t Login::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Login.Login)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  if (((_has_bits_[0] & 0x00000007) ^ 0x00000007) == 0) {  // All required fields are present.
    // required bytes name = 2;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->name());

    // required int32 msgId = 1;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->msgid());

    // required int32 password = 3;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->password());

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Login::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Login.Login)
  GOOGLE_DCHECK_NE(&from, this);
  const Login* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const Login>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Login.Login)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Login.Login)
    MergeFrom(*source);
  }
}

void Login::MergeFrom(const Login& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Login.Login)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 7u) {
    if (cached_has_bits & 0x00000001u) {
      set_has_name();
      name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.name_);
    }
    if (cached_has_bits & 0x00000002u) {
      msgid_ = from.msgid_;
    }
    if (cached_has_bits & 0x00000004u) {
      password_ = from.password_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void Login::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Login.Login)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Login::CopyFrom(const Login& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Login.Login)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Login::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000007) != 0x00000007) return false;
  return true;
}

void Login::Swap(Login* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Login::InternalSwap(Login* other) {
  using std::swap;
  name_.Swap(&other->name_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(msgid_, other->msgid_);
  swap(password_, other->password_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata Login::GetMetadata() const {
  protobuf_login_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_login_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void LoginSuccess::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int LoginSuccess::kMsgIdFieldNumber;
const int LoginSuccess::kNameFieldNumber;
const int LoginSuccess::kIdFieldNumber;
const int LoginSuccess::kEmailFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

LoginSuccess::LoginSuccess()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_login_2eproto::scc_info_LoginSuccess.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:Login.LoginSuccess)
}
LoginSuccess::LoginSuccess(const LoginSuccess& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_name()) {
    name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.name_);
  }
  email_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_email()) {
    email_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.email_);
  }
  ::memcpy(&msgid_, &from.msgid_,
    static_cast<size_t>(reinterpret_cast<char*>(&id_) -
    reinterpret_cast<char*>(&msgid_)) + sizeof(id_));
  // @@protoc_insertion_point(copy_constructor:Login.LoginSuccess)
}

void LoginSuccess::SharedCtor() {
  name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  email_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&msgid_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&id_) -
      reinterpret_cast<char*>(&msgid_)) + sizeof(id_));
}

LoginSuccess::~LoginSuccess() {
  // @@protoc_insertion_point(destructor:Login.LoginSuccess)
  SharedDtor();
}

void LoginSuccess::SharedDtor() {
  name_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  email_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void LoginSuccess::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* LoginSuccess::descriptor() {
  ::protobuf_login_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_login_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const LoginSuccess& LoginSuccess::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_login_2eproto::scc_info_LoginSuccess.base);
  return *internal_default_instance();
}


void LoginSuccess::Clear() {
// @@protoc_insertion_point(message_clear_start:Login.LoginSuccess)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 3u) {
    if (cached_has_bits & 0x00000001u) {
      name_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000002u) {
      email_.ClearNonDefaultToEmptyNoArena();
    }
  }
  if (cached_has_bits & 12u) {
    ::memset(&msgid_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&id_) -
        reinterpret_cast<char*>(&msgid_)) + sizeof(id_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool LoginSuccess::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Login.LoginSuccess)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 msgId = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {
          set_has_msgid();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &msgid_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required bytes name = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_name()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required int32 id = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(24u /* 24 & 0xFF */)) {
          set_has_id();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &id_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional bytes email = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(34u /* 34 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_email()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:Login.LoginSuccess)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Login.LoginSuccess)
  return false;
#undef DO_
}

void LoginSuccess::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Login.LoginSuccess)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required int32 msgId = 1;
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->msgid(), output);
  }

  // required bytes name = 2;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      2, this->name(), output);
  }

  // required int32 id = 3;
  if (cached_has_bits & 0x00000008u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->id(), output);
  }

  // optional bytes email = 4;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      4, this->email(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:Login.LoginSuccess)
}

::google::protobuf::uint8* LoginSuccess::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:Login.LoginSuccess)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required int32 msgId = 1;
  if (cached_has_bits & 0x00000004u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->msgid(), target);
  }

  // required bytes name = 2;
  if (cached_has_bits & 0x00000001u) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        2, this->name(), target);
  }

  // required int32 id = 3;
  if (cached_has_bits & 0x00000008u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->id(), target);
  }

  // optional bytes email = 4;
  if (cached_has_bits & 0x00000002u) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        4, this->email(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Login.LoginSuccess)
  return target;
}

size_t LoginSuccess::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:Login.LoginSuccess)
  size_t total_size = 0;

  if (has_name()) {
    // required bytes name = 2;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->name());
  }

  if (has_msgid()) {
    // required int32 msgId = 1;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->msgid());
  }

  if (has_id()) {
    // required int32 id = 3;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->id());
  }

  return total_size;
}
size_t LoginSuccess::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Login.LoginSuccess)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  if (((_has_bits_[0] & 0x0000000d) ^ 0x0000000d) == 0) {  // All required fields are present.
    // required bytes name = 2;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->name());

    // required int32 msgId = 1;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->msgid());

    // required int32 id = 3;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->id());

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  // optional bytes email = 4;
  if (has_email()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->email());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void LoginSuccess::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Login.LoginSuccess)
  GOOGLE_DCHECK_NE(&from, this);
  const LoginSuccess* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const LoginSuccess>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Login.LoginSuccess)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Login.LoginSuccess)
    MergeFrom(*source);
  }
}

void LoginSuccess::MergeFrom(const LoginSuccess& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Login.LoginSuccess)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 15u) {
    if (cached_has_bits & 0x00000001u) {
      set_has_name();
      name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.name_);
    }
    if (cached_has_bits & 0x00000002u) {
      set_has_email();
      email_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.email_);
    }
    if (cached_has_bits & 0x00000004u) {
      msgid_ = from.msgid_;
    }
    if (cached_has_bits & 0x00000008u) {
      id_ = from.id_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void LoginSuccess::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Login.LoginSuccess)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void LoginSuccess::CopyFrom(const LoginSuccess& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Login.LoginSuccess)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool LoginSuccess::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000000d) != 0x0000000d) return false;
  return true;
}

void LoginSuccess::Swap(LoginSuccess* other) {
  if (other == this) return;
  InternalSwap(other);
}
void LoginSuccess::InternalSwap(LoginSuccess* other) {
  using std::swap;
  name_.Swap(&other->name_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  email_.Swap(&other->email_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(msgid_, other->msgid_);
  swap(id_, other->id_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata LoginSuccess::GetMetadata() const {
  protobuf_login_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_login_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace Login
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::Login::Login* Arena::CreateMaybeMessage< ::Login::Login >(Arena* arena) {
  return Arena::CreateInternal< ::Login::Login >(arena);
}
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::Login::LoginSuccess* Arena::CreateMaybeMessage< ::Login::LoginSuccess >(Arena* arena) {
  return Arena::CreateInternal< ::Login::LoginSuccess >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
