/**
 Copyright (c) 2015-present, Facebook, Inc.
 All rights reserved.

 This source code is licensed under the BSD-style license found in the
 LICENSE file in the root directory of this source tree. An additional grant
 of patent rights can be found in the PATENTS file in the same directory.
 */

#ifndef __pbxspec_PBX_Tool_h
#define __pbxspec_PBX_Tool_h

#include <pbxspec/PBX/Specification.h>
#include <pbxspec/PBX/PropertyOption.h>

namespace pbxspec { namespace PBX {

class Tool : public Specification {
public:
    typedef std::shared_ptr <Tool> shared_ptr;
    typedef std::vector <shared_ptr> vector;

protected:
    pbxsetting::Value               _execPath;
    pbxsetting::Value               _execDescription;
    pbxsetting::Value               _execDescriptionForPrecompile;
    pbxsetting::Value               _execDescriptionForCompile;
    pbxsetting::Value               _execDescriptionForCreateBitcode;
    pbxsetting::Value               _progressDescription;
    pbxsetting::Value               _progressDescriptionForPrecompile;
    pbxsetting::Value               _progressDescriptionForCompile;
    pbxsetting::Value               _progressDescriptionForCreateBitcode;
    pbxsetting::Value               _commandLine;
    std::string                     _commandInvocationClass;
    pbxsetting::Value               _commandIdentifier;
    pbxsetting::Value               _ruleName;
    pbxsetting::Value               _ruleFormat;
    pbxsetting::Value               _additionalInputFiles;
    std::string                     _builtinJambaseRuleName;
    std::vector<std::string>        _fileTypes;
    std::vector<std::string>        _inputFileTypes;
    std::vector<std::string>        _architectures;
    std::vector<pbxsetting::Value>  _outputs;
    std::unordered_set<std::string> _deletedProperties;
    std::unordered_map<std::string, pbxsetting::Value> _environmentVariables;
    std::vector<int>                _successExitCodes;
    plist::Object                  *_commandOutputParser;
    bool                            _isAbstract;
    bool                            _isArchitectureNeutral;
    bool                            _caresAboutInclusionDependencies;
    bool                            _synthesizeBuildRule;
    bool                            _shouldRerunOnError;
    bool                            _deeplyStatInputDirectories;
    bool                            _isUnsafeToInterrupt;
    int                             _messageLimit;
    PropertyOption::vector          _options;
    PropertyOption::used_map        _optionsUsed;

protected:
    Tool();

public:
    virtual ~Tool();

public:
    inline char const *type() const override
    { return Tool::Type(); }

public:
    inline Tool::shared_ptr const &base() const
    { return reinterpret_cast <Tool::shared_ptr const &> (Specification::base()); }

public:
    inline pbxsetting::Value const &execPath() const
    { return _execPath; }

public:
    inline pbxsetting::Value const &execDescription() const
    { return _execDescription; }
    inline pbxsetting::Value const &execDescriptionForPrecompile() const
    { return _execDescriptionForPrecompile; }
    inline pbxsetting::Value const &execDescriptionForCompile() const
    { return _execDescriptionForCompile; }
    inline pbxsetting::Value const &execDescriptionForCreateBitcode() const
    { return _execDescriptionForCreateBitcode; }

public:
    inline pbxsetting::Value const &progressDescription() const
    { return _progressDescription; }
    inline pbxsetting::Value const &progressDescriptionForPrecompile() const
    { return _progressDescriptionForPrecompile; }
    inline pbxsetting::Value const &progressDescriptionForCompile() const
    { return _progressDescriptionForCompile; }
    inline pbxsetting::Value const &progressDescriptionForCreateBitcode() const
    { return _progressDescriptionForCreateBitcode; }

public:
    inline pbxsetting::Value const &commandLine() const
    { return _commandLine; }

public:
    inline std::string const &commandInvocationClass() const
    { return _commandInvocationClass; }
    inline pbxsetting::Value const &commandIdentifier() const
    { return _commandIdentifier; }

public:
    inline pbxsetting::Value const &ruleName() const
    { return _ruleName; }
    inline pbxsetting::Value const &ruleFormat() const
    { return _ruleFormat; }
    inline std::string const &builtinJambaseRuleName() const
    { return _builtinJambaseRuleName; }

public:
    inline pbxsetting::Value const &additionalInputFiles() const
    { return _additionalInputFiles; }

public:
    inline std::vector<std::string> const &fileTypes() const
    { return _fileTypes; }
    inline std::vector<std::string> const &inputFileTypes() const
    { return _inputFileTypes; }

public:
    inline std::vector<std::string> const &architectures() const
    { return _architectures; }

public:
    inline std::vector<pbxsetting::Value> const &outputs() const
    { return _outputs; }

public:
    inline std::unordered_map<std::string, pbxsetting::Value> const &environmentVariables() const
    { return _environmentVariables; }

public:
    inline std::vector<int> const &successExitCodes() const
    { return _successExitCodes; }

public:
    inline plist::Object const *commandOutputParser() const
    { return _commandOutputParser; }

public:
    inline bool isAbstract() const
    { return _isAbstract; }

public:
    inline bool isArchitectureNeutral() const
    { return _isArchitectureNeutral; }

public:
    inline bool caresAboutInclusionDependencies() const
    { return _caresAboutInclusionDependencies; }

public:
    inline bool synthesizeBuildRule() const
    { return _synthesizeBuildRule; }

public:
    inline bool shouldRerunOnError() const
    { return _shouldRerunOnError; }

public:
    inline bool deeplyStatInputDirectories() const
    { return _deeplyStatInputDirectories; }

public:
    inline bool isUnsafeToInterrupt() const
    { return _isUnsafeToInterrupt; }

public:
    inline int messageLimit() const
    { return _messageLimit; }

public:
    inline PropertyOption::vector const &options() const
    { return _options; }

public:
    inline std::unordered_set<std::string> const &deletedProperties() const
    { return _deletedProperties; }

public:
    pbxsetting::Level defaultSettings(void) const;

protected:
    friend class Specification;
    bool parse(Context *context, plist::Dictionary const *dict, std::unordered_set<std::string> *seen, bool check) override;

protected:
    bool inherit(Specification::shared_ptr const &base) override;
    virtual bool inherit(Tool::shared_ptr const &base);

protected:
    static Tool::shared_ptr Parse(Context *context, plist::Dictionary const *dict);

public:
    static inline char const *Type()
    { return Types::Tool; }
};

} }

#endif  // !__pbxspec_PBX_Tool_h
