// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: programmer.proto

#include "programmer.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
constexpr Programmer_ProjsEntry_DoNotUse::Programmer_ProjsEntry_DoNotUse(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized){}
struct Programmer_ProjsEntry_DoNotUseDefaultTypeInternal {
  constexpr Programmer_ProjsEntry_DoNotUseDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~Programmer_ProjsEntry_DoNotUseDefaultTypeInternal() {}
  union {
    Programmer_ProjsEntry_DoNotUse _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT Programmer_ProjsEntry_DoNotUseDefaultTypeInternal _Programmer_ProjsEntry_DoNotUse_default_instance_;
constexpr Programmer::Programmer(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : lang_()
  , book_()
  , projs_(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{})
  , name_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , phone_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , address_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , age_(0){}
struct ProgrammerDefaultTypeInternal {
  constexpr ProgrammerDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~ProgrammerDefaultTypeInternal() {}
  union {
    Programmer _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT ProgrammerDefaultTypeInternal _Programmer_default_instance_;
constexpr Project::Project(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : name_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , price_(0){}
struct ProjectDefaultTypeInternal {
  constexpr ProjectDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~ProjectDefaultTypeInternal() {}
  union {
    Project _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT ProjectDefaultTypeInternal _Project_default_instance_;
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_programmer_2eproto[3];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_programmer_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_programmer_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_programmer_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::Programmer_ProjsEntry_DoNotUse, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::Programmer_ProjsEntry_DoNotUse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::Programmer_ProjsEntry_DoNotUse, key_),
  PROTOBUF_FIELD_OFFSET(::Programmer_ProjsEntry_DoNotUse, value_),
  0,
  1,
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Programmer, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::Programmer, name_),
  PROTOBUF_FIELD_OFFSET(::Programmer, age_),
  PROTOBUF_FIELD_OFFSET(::Programmer, phone_),
  PROTOBUF_FIELD_OFFSET(::Programmer, address_),
  PROTOBUF_FIELD_OFFSET(::Programmer, lang_),
  PROTOBUF_FIELD_OFFSET(::Programmer, book_),
  PROTOBUF_FIELD_OFFSET(::Programmer, projs_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Project, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::Project, name_),
  PROTOBUF_FIELD_OFFSET(::Project, price_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 7, sizeof(::Programmer_ProjsEntry_DoNotUse)},
  { 9, -1, sizeof(::Programmer)},
  { 21, -1, sizeof(::Project)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_Programmer_ProjsEntry_DoNotUse_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_Programmer_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_Project_default_instance_),
};

const char descriptor_table_protodef_programmer_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\020programmer.proto\"\302\001\n\nProgrammer\022\014\n\004nam"
  "e\030\001 \001(\t\022\013\n\003age\030\002 \001(\005\022\r\n\005phone\030\003 \001(\t\022\017\n\007a"
  "ddress\030\004 \001(\t\022\014\n\004lang\030\005 \003(\t\022\014\n\004book\030\006 \003(\t"
  "\022%\n\005projs\030\007 \003(\0132\026.Programmer.ProjsEntry\032"
  "6\n\nProjsEntry\022\013\n\003key\030\001 \001(\t\022\027\n\005value\030\002 \001("
  "\0132\010.Project:\0028\001\"&\n\007Project\022\014\n\004name\030\001 \001(\t"
  "\022\r\n\005price\030\002 \001(\002b\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_programmer_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_programmer_2eproto = {
  false, false, 263, descriptor_table_protodef_programmer_2eproto, "programmer.proto", 
  &descriptor_table_programmer_2eproto_once, nullptr, 0, 3,
  schemas, file_default_instances, TableStruct_programmer_2eproto::offsets,
  file_level_metadata_programmer_2eproto, file_level_enum_descriptors_programmer_2eproto, file_level_service_descriptors_programmer_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_programmer_2eproto_getter() {
  return &descriptor_table_programmer_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_programmer_2eproto(&descriptor_table_programmer_2eproto);

// ===================================================================

Programmer_ProjsEntry_DoNotUse::Programmer_ProjsEntry_DoNotUse() {}
Programmer_ProjsEntry_DoNotUse::Programmer_ProjsEntry_DoNotUse(::PROTOBUF_NAMESPACE_ID::Arena* arena)
    : SuperType(arena) {}
void Programmer_ProjsEntry_DoNotUse::MergeFrom(const Programmer_ProjsEntry_DoNotUse& other) {
  MergeFromInternal(other);
}
::PROTOBUF_NAMESPACE_ID::Metadata Programmer_ProjsEntry_DoNotUse::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_programmer_2eproto_getter, &descriptor_table_programmer_2eproto_once,
      file_level_metadata_programmer_2eproto[0]);
}
void Programmer_ProjsEntry_DoNotUse::MergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::Message& other) {
  ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom(other);
}


// ===================================================================

class Programmer::_Internal {
 public:
};

Programmer::Programmer(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  lang_(arena),
  book_(arena),
  projs_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:Programmer)
}
Programmer::Programmer(const Programmer& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      lang_(from.lang_),
      book_(from.book_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  projs_.MergeFrom(from.projs_);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_name().empty()) {
    name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_name(), 
      GetArenaForAllocation());
  }
  phone_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_phone().empty()) {
    phone_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_phone(), 
      GetArenaForAllocation());
  }
  address_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_address().empty()) {
    address_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_address(), 
      GetArenaForAllocation());
  }
  age_ = from.age_;
  // @@protoc_insertion_point(copy_constructor:Programmer)
}

void Programmer::SharedCtor() {
name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
phone_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
address_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
age_ = 0;
}

Programmer::~Programmer() {
  // @@protoc_insertion_point(destructor:Programmer)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void Programmer::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  phone_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  address_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Programmer::ArenaDtor(void* object) {
  Programmer* _this = reinterpret_cast< Programmer* >(object);
  (void)_this;
  _this->projs_. ~MapField();
}
inline void Programmer::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena) {
  if (arena != nullptr) {
    arena->OwnCustomDestructor(this, &Programmer::ArenaDtor);
  }
}
void Programmer::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Programmer::Clear() {
// @@protoc_insertion_point(message_clear_start:Programmer)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  lang_.Clear();
  book_.Clear();
  projs_.Clear();
  name_.ClearToEmpty();
  phone_.ClearToEmpty();
  address_.ClearToEmpty();
  age_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Programmer::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Programmer.name"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int32 age = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          age_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string phone = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          auto str = _internal_mutable_phone();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Programmer.phone"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string address = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          auto str = _internal_mutable_address();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Programmer.address"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated string lang = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42)) {
          ptr -= 1;
          do {
            ptr += 1;
            auto str = _internal_add_lang();
            ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
            CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Programmer.lang"));
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<42>(ptr));
        } else goto handle_unusual;
        continue;
      // repeated string book = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 50)) {
          ptr -= 1;
          do {
            ptr += 1;
            auto str = _internal_add_book();
            ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
            CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Programmer.book"));
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<50>(ptr));
        } else goto handle_unusual;
        continue;
      // map<string, .Project> projs = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 58)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(&projs_, ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<58>(ptr));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag == 0) || ((tag & 7) == 4)) {
          CHK_(ptr);
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Programmer::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Programmer)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string name = 1;
  if (!this->name().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Programmer.name");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_name(), target);
  }

  // int32 age = 2;
  if (this->age() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(2, this->_internal_age(), target);
  }

  // string phone = 3;
  if (!this->phone().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_phone().data(), static_cast<int>(this->_internal_phone().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Programmer.phone");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_phone(), target);
  }

  // string address = 4;
  if (!this->address().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_address().data(), static_cast<int>(this->_internal_address().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Programmer.address");
    target = stream->WriteStringMaybeAliased(
        4, this->_internal_address(), target);
  }

  // repeated string lang = 5;
  for (int i = 0, n = this->_internal_lang_size(); i < n; i++) {
    const auto& s = this->_internal_lang(i);
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      s.data(), static_cast<int>(s.length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Programmer.lang");
    target = stream->WriteString(5, s, target);
  }

  // repeated string book = 6;
  for (int i = 0, n = this->_internal_book_size(); i < n; i++) {
    const auto& s = this->_internal_book(i);
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      s.data(), static_cast<int>(s.length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Programmer.book");
    target = stream->WriteString(6, s, target);
  }

  // map<string, .Project> projs = 7;
  if (!this->_internal_projs().empty()) {
    typedef ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::Project >::const_pointer
        ConstPtr;
    typedef ConstPtr SortItem;
    typedef ::PROTOBUF_NAMESPACE_ID::internal::CompareByDerefFirst<SortItem> Less;
    struct Utf8Check {
      static void Check(ConstPtr p) {
        (void)p;
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
          p->first.data(), static_cast<int>(p->first.length()),
          ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
          "Programmer.ProjsEntry.key");
      }
    };

    if (stream->IsSerializationDeterministic() &&
        this->_internal_projs().size() > 1) {
      ::std::unique_ptr<SortItem[]> items(
          new SortItem[this->_internal_projs().size()]);
      typedef ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::Project >::size_type size_type;
      size_type n = 0;
      for (::PROTOBUF_NAMESPACE_ID::Map< std::string, ::Project >::const_iterator
          it = this->_internal_projs().begin();
          it != this->_internal_projs().end(); ++it, ++n) {
        items[static_cast<ptrdiff_t>(n)] = SortItem(&*it);
      }
      ::std::sort(&items[0], &items[static_cast<ptrdiff_t>(n)], Less());
      for (size_type i = 0; i < n; i++) {
        target = Programmer_ProjsEntry_DoNotUse::Funcs::InternalSerialize(7, items[static_cast<ptrdiff_t>(i)]->first, items[static_cast<ptrdiff_t>(i)]->second, target, stream);
        Utf8Check::Check(&(*items[static_cast<ptrdiff_t>(i)]));
      }
    } else {
      for (::PROTOBUF_NAMESPACE_ID::Map< std::string, ::Project >::const_iterator
          it = this->_internal_projs().begin();
          it != this->_internal_projs().end(); ++it) {
        target = Programmer_ProjsEntry_DoNotUse::Funcs::InternalSerialize(7, it->first, it->second, target, stream);
        Utf8Check::Check(&(*it));
      }
    }
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Programmer)
  return target;
}

size_t Programmer::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Programmer)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated string lang = 5;
  total_size += 1 *
      ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(lang_.size());
  for (int i = 0, n = lang_.size(); i < n; i++) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
      lang_.Get(i));
  }

  // repeated string book = 6;
  total_size += 1 *
      ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(book_.size());
  for (int i = 0, n = book_.size(); i < n; i++) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
      book_.Get(i));
  }

  // map<string, .Project> projs = 7;
  total_size += 1 *
      ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(this->_internal_projs_size());
  for (::PROTOBUF_NAMESPACE_ID::Map< std::string, ::Project >::const_iterator
      it = this->_internal_projs().begin();
      it != this->_internal_projs().end(); ++it) {
    total_size += Programmer_ProjsEntry_DoNotUse::Funcs::ByteSizeLong(it->first, it->second);
  }

  // string name = 1;
  if (!this->name().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());
  }

  // string phone = 3;
  if (!this->phone().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_phone());
  }

  // string address = 4;
  if (!this->address().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_address());
  }

  // int32 age = 2;
  if (this->age() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_age());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Programmer::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Programmer)
  GOOGLE_DCHECK_NE(&from, this);
  const Programmer* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Programmer>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Programmer)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Programmer)
    MergeFrom(*source);
  }
}

void Programmer::MergeFrom(const Programmer& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Programmer)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  lang_.MergeFrom(from.lang_);
  book_.MergeFrom(from.book_);
  projs_.MergeFrom(from.projs_);
  if (!from.name().empty()) {
    _internal_set_name(from._internal_name());
  }
  if (!from.phone().empty()) {
    _internal_set_phone(from._internal_phone());
  }
  if (!from.address().empty()) {
    _internal_set_address(from._internal_address());
  }
  if (from.age() != 0) {
    _internal_set_age(from._internal_age());
  }
}

void Programmer::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Programmer)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Programmer::CopyFrom(const Programmer& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Programmer)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Programmer::IsInitialized() const {
  return true;
}

void Programmer::InternalSwap(Programmer* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  lang_.InternalSwap(&other->lang_);
  book_.InternalSwap(&other->book_);
  projs_.InternalSwap(&other->projs_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &name_, GetArenaForAllocation(),
      &other->name_, other->GetArenaForAllocation()
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &phone_, GetArenaForAllocation(),
      &other->phone_, other->GetArenaForAllocation()
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &address_, GetArenaForAllocation(),
      &other->address_, other->GetArenaForAllocation()
  );
  swap(age_, other->age_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Programmer::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_programmer_2eproto_getter, &descriptor_table_programmer_2eproto_once,
      file_level_metadata_programmer_2eproto[1]);
}

// ===================================================================

class Project::_Internal {
 public:
};

Project::Project(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:Project)
}
Project::Project(const Project& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_name().empty()) {
    name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_name(), 
      GetArenaForAllocation());
  }
  price_ = from.price_;
  // @@protoc_insertion_point(copy_constructor:Project)
}

void Project::SharedCtor() {
name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
price_ = 0;
}

Project::~Project() {
  // @@protoc_insertion_point(destructor:Project)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void Project::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Project::ArenaDtor(void* object) {
  Project* _this = reinterpret_cast< Project* >(object);
  (void)_this;
}
void Project::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Project::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Project::Clear() {
// @@protoc_insertion_point(message_clear_start:Project)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  name_.ClearToEmpty();
  price_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Project::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Project.name"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // float price = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 21)) {
          price_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag == 0) || ((tag & 7) == 4)) {
          CHK_(ptr);
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Project::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Project)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string name = 1;
  if (!this->name().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Project.name");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_name(), target);
  }

  // float price = 2;
  if (!(this->price() <= 0 && this->price() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(2, this->_internal_price(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Project)
  return target;
}

size_t Project::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Project)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string name = 1;
  if (!this->name().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());
  }

  // float price = 2;
  if (!(this->price() <= 0 && this->price() >= 0)) {
    total_size += 1 + 4;
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Project::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Project)
  GOOGLE_DCHECK_NE(&from, this);
  const Project* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Project>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Project)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Project)
    MergeFrom(*source);
  }
}

void Project::MergeFrom(const Project& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Project)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from.name().empty()) {
    _internal_set_name(from._internal_name());
  }
  if (!(from.price() <= 0 && from.price() >= 0)) {
    _internal_set_price(from._internal_price());
  }
}

void Project::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Project)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Project::CopyFrom(const Project& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Project)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Project::IsInitialized() const {
  return true;
}

void Project::InternalSwap(Project* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &name_, GetArenaForAllocation(),
      &other->name_, other->GetArenaForAllocation()
  );
  swap(price_, other->price_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Project::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_programmer_2eproto_getter, &descriptor_table_programmer_2eproto_once,
      file_level_metadata_programmer_2eproto[2]);
}

// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Programmer_ProjsEntry_DoNotUse* Arena::CreateMaybeMessage< ::Programmer_ProjsEntry_DoNotUse >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Programmer_ProjsEntry_DoNotUse >(arena);
}
template<> PROTOBUF_NOINLINE ::Programmer* Arena::CreateMaybeMessage< ::Programmer >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Programmer >(arena);
}
template<> PROTOBUF_NOINLINE ::Project* Arena::CreateMaybeMessage< ::Project >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Project >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>