/*
 * UserGroupInformation.h
 *
 *  Created on: Jul 7, 2012
 *      Author: yank1
 */

#ifndef USERGROUPINFORMATION_H_
#define USERGROUPINFORMATION_H_

#include <memory>
#include <string>
#include <sstream>
#include <stdlib.h>

#include "util/Logger.h"
#include "User.h"
#include "AuthenticationMethod.h"
using namespace std;

namespace libhadoop {

class UserGroupInformation {

public:
	static const string HADOOP_TOKEN_FILE_LOCATION;

	UserGroupInformation();

	string toString();
	string getUserName();
	AuthenticationMethod getAuthenticationMethod();
	string authenticationMethodToString(AuthenticationMethod authMethod);
	static bool isSecurityEnabled();
	static UserGroupInformation& getLoginUser();
	static UserGroupInformation& getCurrentUser();
private:
	User user;
	string clientName;

//	UserGroupInformation(const UserGroupInformation& ugi);

	void setAuthenticationMethod(AuthenticationMethod authMethod);

	static auto_ptr<UserGroupInformation> loginUser;

};

} /* namespace libhadoop */
#endif /* USERGROUPINFORMATION_H_ */
