/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "thrift/compiler/test/fixtures/complex-union/gen-cpp/module_types.h"
#include "thrift/compiler/test/fixtures/complex-union/gen-cpp/module_data.h"

#include "thrift/compiler/test/fixtures/complex-union/gen-cpp/module_reflection.h"

#include <algorithm>
#include <string.h>

#include <folly/Indestructible.h>



uint32_t ComplexUnion::read(apache::thrift::protocol::TProtocol* iprot) {
  uint32_t xfer = 0;
  std::string fname;
  apache::thrift::protocol::TType ftype;
  int16_t fid;
  xfer += iprot->readStructBegin(fname);
  xfer += iprot->readFieldBegin(fname, ftype, fid);
  if (ftype == apache::thrift::protocol::T_STOP) {
    __clear();
  } else {
    switch (fid) {
      case 1: {
        if (ftype == apache::thrift::protocol::T_I64) {
          set_intValue();
          xfer += iprot->readI64(this->value_.intValue);
        } else {
        xfer += iprot->skip(ftype);
        }
        break;
      }
      case 5: {
        if (ftype == apache::thrift::protocol::T_STRING) {
          set_stringValue();
          xfer += iprot->readString(this->value_.stringValue);
        } else {
        xfer += iprot->skip(ftype);
        }
        break;
      }
      case 2: {
        if (ftype == apache::thrift::protocol::T_LIST) {
          set_intListValue();
          {
            this->value_.intListValue.clear();
            uint32_t _size0;
            bool _sizeUnknown1;
            apache::thrift::protocol::TType _etype4;
            xfer += iprot->readListBegin(_etype4, _size0, _sizeUnknown1);
            if (!_sizeUnknown1) {
              this->value_.intListValue.resize(_size0);
              uint32_t _i6;
              for (_i6 = 0; _i6 < _size0; ++_i6)
              {
                xfer += iprot->readI64(this->value_.intListValue[_i6]);
              }
            } else {
              while (iprot->peekList())
              {
                int64_t _elem7;
                xfer += iprot->readI64(_elem7);
                this->value_.intListValue.push_back(_elem7);
              }
            }
            xfer += iprot->readListEnd();
          }
        } else {
        xfer += iprot->skip(ftype);
        }
        break;
      }
      case 3: {
        if (ftype == apache::thrift::protocol::T_LIST) {
          set_stringListValue();
          {
            this->value_.stringListValue.clear();
            uint32_t _size8;
            bool _sizeUnknown9;
            apache::thrift::protocol::TType _etype12;
            xfer += iprot->readListBegin(_etype12, _size8, _sizeUnknown9);
            if (!_sizeUnknown9) {
              this->value_.stringListValue.resize(_size8);
              uint32_t _i14;
              for (_i14 = 0; _i14 < _size8; ++_i14)
              {
                xfer += iprot->readString(this->value_.stringListValue[_i14]);
              }
            } else {
              while (iprot->peekList())
              {
                std::string _elem15;
                xfer += iprot->readString(_elem15);
                this->value_.stringListValue.push_back(_elem15);
              }
            }
            xfer += iprot->readListEnd();
          }
        } else {
        xfer += iprot->skip(ftype);
        }
        break;
      }
      case 9: {
        if (ftype == apache::thrift::protocol::T_MAP) {
          set_typedefValue();
          {
            this->value_.typedefValue.clear();
            uint32_t _size16;
            bool _sizeUnknown17;
            apache::thrift::protocol::TType _ktype18;
            apache::thrift::protocol::TType _vtype19;
            xfer += iprot->readMapBegin(_ktype18, _vtype19, _size16, _sizeUnknown17);
            if (!_sizeUnknown17) {
              uint32_t _i22;
              for (_i22 = 0; _i22 < _size16; ++_i22)
              {
                int16_t _key23;
                xfer += iprot->readI16(_key23);
                std::string& _val24 = this->value_.typedefValue[_key23];
                xfer += iprot->readString(_val24);
              }
            } else {
              while (iprot->peekMap())
              {
                int16_t _key25;
                xfer += iprot->readI16(_key25);
                std::string& _val26 = this->value_.typedefValue[_key25];
                xfer += iprot->readString(_val26);
              }
            }
            xfer += iprot->readMapEnd();
          }
        } else {
        xfer += iprot->skip(ftype);
        }
        break;
      }
      case 14: {
        if (ftype == apache::thrift::protocol::T_STRING) {
          set_stringRef();
          xfer += iprot->readString(this->value_.stringRef);
        } else {
        xfer += iprot->skip(ftype);
        }
        break;
      }
      default: xfer += iprot->skip(ftype); break;
    }
    xfer += iprot->readFieldEnd();
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (UNLIKELY(ftype != apache::thrift::protocol::T_STOP)) {
      using apache::thrift::protocol::TProtocolException;
      TProtocolException::throwUnionMissingStop();
    }
  }
  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ComplexUnion::write(apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("ComplexUnion");
  switch (type_) {
    case Type::intValue: {
      xfer += oprot->writeFieldBegin("intValue", apache::thrift::protocol::T_I64, 1);
      xfer += oprot->writeI64(this->value_.intValue);
      xfer += oprot->writeFieldEnd();
      break;
    }
    case Type::stringValue: {
      xfer += oprot->writeFieldBegin("stringValue", apache::thrift::protocol::T_STRING, 5);
      xfer += oprot->writeString(this->value_.stringValue);
      xfer += oprot->writeFieldEnd();
      break;
    }
    case Type::intListValue: {
      xfer += oprot->writeFieldBegin("intListValue", apache::thrift::protocol::T_LIST, 2);
      {
        xfer += oprot->writeListBegin(apache::thrift::protocol::T_I64, this->value_.intListValue.size());
        std::vector<int64_t> ::const_iterator _iter27;
        for (_iter27 = this->value_.intListValue.begin(); _iter27 != this->value_.intListValue.end(); ++_iter27)
        {
          xfer += oprot->writeI64((*_iter27));
        }
        xfer += oprot->writeListEnd();
      }
      xfer += oprot->writeFieldEnd();
      break;
    }
    case Type::stringListValue: {
      xfer += oprot->writeFieldBegin("stringListValue", apache::thrift::protocol::T_LIST, 3);
      {
        xfer += oprot->writeListBegin(apache::thrift::protocol::T_STRING, this->value_.stringListValue.size());
        std::vector<std::string> ::const_iterator _iter28;
        for (_iter28 = this->value_.stringListValue.begin(); _iter28 != this->value_.stringListValue.end(); ++_iter28)
        {
          xfer += oprot->writeString((*_iter28));
        }
        xfer += oprot->writeListEnd();
      }
      xfer += oprot->writeFieldEnd();
      break;
    }
    case Type::typedefValue: {
      xfer += oprot->writeFieldBegin("typedefValue", apache::thrift::protocol::T_MAP, 9);
      {
        xfer += oprot->writeMapBegin(apache::thrift::protocol::T_I16, apache::thrift::protocol::T_STRING, this->value_.typedefValue.size());
        std::map<int16_t, std::string> ::const_iterator _iter29;
        for (_iter29 = this->value_.typedefValue.begin(); _iter29 != this->value_.typedefValue.end(); ++_iter29)
        {
          xfer += oprot->writeI16(_iter29->first);
          xfer += oprot->writeString(_iter29->second);
        }
        xfer += oprot->writeMapEnd();
      }
      xfer += oprot->writeFieldEnd();
      break;
    }
    case Type::stringRef: {
      xfer += oprot->writeFieldBegin("stringRef", apache::thrift::protocol::T_STRING, 14);
      xfer += oprot->writeString(this->value_.stringRef);
      xfer += oprot->writeFieldEnd();
      break;
    }
    case Type::__EMPTY__:;
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

uint32_t FinalComplexUnion::read(apache::thrift::protocol::TProtocol* iprot) {
  uint32_t xfer = 0;
  std::string fname;
  apache::thrift::protocol::TType ftype;
  int16_t fid;
  xfer += iprot->readStructBegin(fname);
  xfer += iprot->readFieldBegin(fname, ftype, fid);
  if (ftype == apache::thrift::protocol::T_STOP) {
    __clear();
  } else {
    switch (fid) {
      case 1: {
        if (ftype == apache::thrift::protocol::T_STRING) {
          set_thingOne();
          xfer += iprot->readString(this->value_.thingOne);
        } else {
        xfer += iprot->skip(ftype);
        }
        break;
      }
      case 2: {
        if (ftype == apache::thrift::protocol::T_STRING) {
          set_thingTwo();
          xfer += iprot->readString(this->value_.thingTwo);
        } else {
        xfer += iprot->skip(ftype);
        }
        break;
      }
      default: xfer += iprot->skip(ftype); break;
    }
    xfer += iprot->readFieldEnd();
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (UNLIKELY(ftype != apache::thrift::protocol::T_STOP)) {
      using apache::thrift::protocol::TProtocolException;
      TProtocolException::throwUnionMissingStop();
    }
  }
  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t FinalComplexUnion::write(apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("FinalComplexUnion");
  switch (type_) {
    case Type::thingOne: {
      xfer += oprot->writeFieldBegin("thingOne", apache::thrift::protocol::T_STRING, 1);
      xfer += oprot->writeString(this->value_.thingOne);
      xfer += oprot->writeFieldEnd();
      break;
    }
    case Type::thingTwo: {
      xfer += oprot->writeFieldBegin("thingTwo", apache::thrift::protocol::T_STRING, 2);
      xfer += oprot->writeString(this->value_.thingTwo);
      xfer += oprot->writeFieldEnd();
      break;
    }
    case Type::__EMPTY__:;
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


