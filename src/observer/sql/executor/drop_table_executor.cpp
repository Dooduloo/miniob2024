//
// Created by lzh on 2025/5/17.
//

#include "sql/executor/drop_table_executor.h"

#include "common/log/log.h"
#include "event/session_event.h"
#include "event/sql_event.h"
#include "session/session.h"
#include "sql/stmt/drop_table_stmt.h"
#include "storage/db/db.h"

RC DropTableExecutor::execute(SQLStageEvent *sql_event)
{
  Stmt    *stmt    = sql_event->stmt();
  Session *session = sql_event->session_event()->session();

  DropTableStmt *drop_table_stmt = static_cast<DropTableStmt *>(stmt);
  
  const char *table_name = drop_table_stmt->table_name().c_str();

  RC rc = session->get_current_db()->drop_table(table_name);

  return rc;
}