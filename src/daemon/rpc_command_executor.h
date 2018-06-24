/**
@file
@details

@image html images/other/runtime-commands.png

*/

// Copyright (c) 2018, Ryo Currency Project
// Portions copyright (c) 2014-2018, The Monero Project
//
// Portions of this file are available under BSD-3 license. Please see ORIGINAL-LICENSE for details
// All rights reserved.
//
// Authors and copyright holders give permission for following:
//
// 1. Redistribution and use in source and binary forms WITHOUT modification.
//
// 2. Modification of the source form for your own personal use.
//
// As long as the following conditions are met:
//
// 3. You must not distribute modified copies of the to third parties. This includes
//    posting the work online, or hosting copies of the modified work for download.
//
// 4. Any derivative version of this work is also covered by this license, including point 8.
//
// 5. Neither the name of the copyright holders nor the names of the authors may be
//    used to endorse or promote products derived from this software without specific
//    prior written permission.
//
// 6. You agree that this licence is governed by and shall be construed in accordance
//    with the laws of England and Wales.
//
// 7. You agree to submit all disputes arising out of or in connection with this licence
//    to the exclusive jurisdiction of the Courts of England and Wales.
//
// Authors and copyright holders agree that:
//
// 8. This licence expires and the work covered by it is released into the
//    public domain on 1st of February 2019
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Parts of this file are originally copyright (c) 2012-2013 The Cryptonote developers

#pragma once

#include <boost/optional/optional_fwd.hpp>

#include "common/common_fwd.h"
#include "common/rpc_client.h"
#include "cryptonote_basic/cryptonote_basic.h"
#include "rpc/core_rpc_server.h"

//#undef RYO_DEFAULT_LOG_CATEGORY
//#define RYO_DEFAULT_LOG_CATEGORY "daemon"

namespace daemonize
{

class t_rpc_command_executor final
{
  private:
	tools::t_rpc_client *m_rpc_client;
	cryptonote::core_rpc_server *m_rpc_server;
	bool m_is_rpc;

  public:
	t_rpc_command_executor(
		uint32_t ip, uint16_t port, const boost::optional<tools::login> &user, bool is_rpc = true, cryptonote::core_rpc_server *rpc_server = NULL);

	~t_rpc_command_executor();

	bool print_peer_list();

	bool print_peer_list_stats();

	bool save_blockchain();

	bool show_hash_rate();

	bool hide_hash_rate();

	bool show_difficulty();

	bool show_status();

	bool print_connections();

	bool print_blockchain_info(uint64_t start_block_index, uint64_t end_block_index);

	bool set_log_level(int8_t level);

	bool set_log_categories(const std::string &categories);

	bool print_height();

	bool print_block_by_hash(crypto::hash block_hash);

	bool print_block_by_height(uint64_t height);

	bool print_transaction(crypto::hash transaction_hash, bool include_hex, bool include_json);

	bool is_key_image_spent(const crypto::key_image &ki);

	bool print_transaction_pool_long();

	bool print_transaction_pool_short();

	bool print_transaction_pool_stats();

	bool start_mining(cryptonote::account_public_address address, uint64_t num_threads, cryptonote::network_type nettype, bool do_background_mining = false, bool ignore_battery = false);

	bool stop_mining();

	bool stop_daemon();

	bool print_status();

	bool get_limit();

	bool get_limit_up();

	bool get_limit_down();

	bool set_limit(int64_t limit_down, int64_t limit_up);

	bool out_peers(uint64_t limit);

	bool in_peers(uint64_t limit);

	bool hard_fork_info(uint8_t version);

	bool print_bans();

	bool ban(const std::string &ip, time_t seconds);

	bool unban(const std::string &ip);

	bool flush_txpool(const std::string &txid);

	bool output_histogram(const std::vector<uint64_t> &amounts, uint64_t min_count, uint64_t max_count);

	bool print_coinbase_tx_sum(uint64_t height, uint64_t count);

	bool alt_chain_info();

	bool print_blockchain_dynamic_stats(uint64_t nblocks);

	bool update(const std::string &command);

	bool relay_tx(const std::string &txid);

	bool sync_info();
};

} // namespace daemonize